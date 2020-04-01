// Fill out your copyright notice in the Description page of Project Settings.

#include "Orb.h"


//Set default values
AOrb::AOrb()
{
	//Base score of the orb
	OrbScore = 1;
}

void AOrb::WasCollected_Implementation()
{
	//Base pickup behaviour
	Super::WasCollected_Implementation();
	//Destroy sphere
	Destroy();
}

int AOrb::GetScore()
{
	return OrbScore;
}