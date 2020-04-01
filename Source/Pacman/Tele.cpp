// Fill out your copyright notice in the Description page of Project Settings.

#include "Tele.h"


// Sets default values
ATele::ATele()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATele::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATele::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

