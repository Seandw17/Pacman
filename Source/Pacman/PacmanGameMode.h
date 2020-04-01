// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PacmanGameMode.generated.h"


UENUM(BlueprintType)
enum class EPacState : uint8
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown

};

UCLASS(minimalapi)
class APacmanGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APacmanGameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//Return the current state
	UFUNCTION(BlueprintPure, Category = "Score")
	EPacState GetCurrentState() const;

	//Sets a new playing state
	void SetCurrentState(EPacState NewState);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	int orbs;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
		bool HasWon;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
		bool IsGameOver;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
		bool IsTextVisible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
		class USoundBase* GameMusic;

	void PlayMusic();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;
	UPROPERTY()
	class UUserWidget* CurrentWidget;

private:
	//Keeps track of the current playing state
	EPacState CurrentState;
	
	TArray<class AOrb*> SpawnedOrbs;

	//Handle any function calls that rely upon changing the playing state
	void HandleNewState(EPacState NewState);
};



