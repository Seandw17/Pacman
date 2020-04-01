// Fill out your copyright notice in the Description page of Project Settings.


#include "Fruit.h"
#include "TimerManager.h"

AFruit::AFruit()
{
	CanKill = false;
}

void AFruit::WasCollected_Implementation()
{
	//Base pickup behaviour
	Super::WasCollected_Implementation();
	//Destroy sphere
	Destroy();
}

void AFruit::StartTimer()
{
	CanKill = true;
	GetWorldTimerManager().SetTimer(TimeHandler, this, &AFruit::StopTimer, Time, false);
	UE_LOG(LogTemp, Warning, TEXT("TimerStarted"));
}

void AFruit::StopTimer()
{
	CanKill = true;
	GetWorldTimerManager().ClearTimer(TimeHandler);
	UE_LOG(LogTemp, Warning, TEXT("TimerStopped"));
}


