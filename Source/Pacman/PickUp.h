// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

UCLASS()
class PACMAN_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//return the mesh for the pickup
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	//Return whether the pickup is active
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();
	//Allows other classes to change whether the pickup is active
	UFUNCTION(BlueprintCallable, Category= "Pickup")
	void SetActive(bool PickupState);

	//What happens when the pickup is collected
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();
protected:
	//True when the pickup can be used and false when the pickup is deactivated
	bool PisActive;

private:
	//Static mesh to represent pick up in the level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent*	PickupMesh;

	
};
