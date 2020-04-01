// Fill out your copyright notice in the Description page of Project Settings.

#include "Ghosts.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "PacmanCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Fruit.h"

// Sets default values
AGhosts::AGhosts()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(60, 70, 100), true);
	BoxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AGhosts::OnOverlapBegin);
	BoxCollision->SetupAttachment(GetCapsuleComponent());
	
	
	GhostRun = false;

}

// Called when the game starts or when spawned
void AGhosts::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGhosts::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AGhosts::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGhosts::Setlocation()
{
	
	
	SetActorLocation(FVector(50,170,20));
}



void AGhosts::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	APacmanCharacter* Pacman = Cast<APacmanCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (OtherActor == Pacman)
		{
		Pacman->UpdateLives(Touch);
		Pacman->SetActorLocation(FVector(-2408, 0, 20));
		Setlocation();
		UE_LOG(LogTemp, Warning, TEXT("Touch"));
		}
		
	}
}


void AGhosts::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

