// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "Orb.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API AOrb : public APickUp
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AOrb();
	
	//Override the WasCollected function - use Implementation because its a blueprint native event
	void WasCollected_Implementation() override;

	//public way to access the orb score
	int GetScore();

protected:
	//Sets the amount of score that the orb gives the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", Meta = (BlueprintProtected = "true"))
	int OrbScore;
};
