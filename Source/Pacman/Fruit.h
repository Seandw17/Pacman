// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "Fruit.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API AFruit : public APickUp
{
	GENERATED_BODY()
public:
	AFruit();

	//Override the WasCollected function - use Implementation because its a blueprint native event
	void WasCollected_Implementation() override;

	FTimerHandle TimeHandler;
	UFUNCTION(BlueprintCallable, Category = "Fruit")
	void StartTimer();
	UFUNCTION(BlueprintCallable, Category = "Fruit")
	void StopTimer();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GhostScare")
		bool CanKill;
protected:
	//Sets the amount of score that the orb gives the player


	float Time = 10.0f;
	
};
