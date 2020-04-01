// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ghosts.generated.h"

UCLASS()
class PACMAN_API AGhosts : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGhosts();
	

	//creating the box component
	UPROPERTY(VisibleAnywhere, Category = "BoxComponent")
		class UBoxComponent* BoxCollision;

	FORCEINLINE class UBoxComponent* GetBoxCollision() const { return BoxCollision; }

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, Category = "Ghost")
		int Touch = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ghost")
		bool GhostRun;

	UFUNCTION(BlueprintCallable, Category = "Ghost")
		void Setlocation();

	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	class AFruit* Fruit;
	
	
};
