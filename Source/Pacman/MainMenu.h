// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API AMainMenu : public AGameModeBase
{

	GENERATED_BODY()
public:
	AMainMenu();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (BlueprintProtected = "true"))
		TSubclassOf<class UUserWidget> HUDWidgetClass;
	UPROPERTY()
		class UUserWidget* CurrentWidget;
	
	
};
