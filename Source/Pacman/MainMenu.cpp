// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Blueprint/UserWidget.h"

AMainMenu::AMainMenu()
{

}

void AMainMenu::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
		CurrentWidget->AddToViewport();
		}
	}
}

void AMainMenu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


