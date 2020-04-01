// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PacmanGameMode.h"
#include "PacmanCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "PacmanCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Orb.h"
#include "PickUp.h"


APacmanGameMode::APacmanGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PrimaryActorTick.bCanEverTick = true;

	if (IsGameOver == true || HasWon == true)
	{
		IsTextVisible = true;
	}
}

void APacmanGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Find all Orb Actors
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOrb::StaticClass(), FoundActors);
	
	for (auto Actor : FoundActors)
	{
		AOrb* SpawnedOrbActors = Cast<AOrb>(Actor);
		if (SpawnedOrbActors)
		{
			SpawnedOrbs.AddUnique(SpawnedOrbActors);

		}
	}
	orbs = SpawnedOrbs.Num();



	SetCurrentState(EPacState::EPlaying);

	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}

	
}

void APacmanGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	APacmanCharacter* PacCharacter = Cast<APacmanCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	
	if (PacCharacter)
	{
		if (PacCharacter->GetCurrentLives() <= 0)
		{
			SetCurrentState(EPacState::EGameOver);
		}
		if (PacCharacter->GetCurrentScore() >= orbs)
		{
			SetCurrentState(EPacState::EWon);
		}

		
	}
	

}

void APacmanGameMode::PlayMusic()
{
	UGameplayStatics::PlaySound2D(this, GameMusic);
}

EPacState APacmanGameMode::GetCurrentState() const
{
	return CurrentState;
}

void APacmanGameMode::SetCurrentState(EPacState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void APacmanGameMode::HandleNewState(EPacState NewState)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

	switch (NewState)
	{
	case EPacState::EPlaying:
	{
		PlayMusic();
		
	}
		break;
	case EPacState::EGameOver:
	{
		IsGameOver = true;
		PlayerController->SetCinematicMode(true, false, false, true, true);
		UE_LOG(LogTemp, Warning, TEXT("GameOver"));
		
	}
		break;
	case EPacState::EWon:
	{
		IsGameOver = true;
		PlayerController->SetCinematicMode(true, false, false, true, true);
		UE_LOG(LogTemp, Warning, TEXT("Won"));
	}
		break;
	case EPacState::EUnknown:
	{
	
	}
		break;
	default:
		break;
	}
}
