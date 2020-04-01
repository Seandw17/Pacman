// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PacmanCharacter.generated.h"

UCLASS(config=Game)
class APacmanCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Collection Sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* CollectionSphere;

	APacmanCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	//function for current score
	UFUNCTION(BlueprintPure, Category = "Score")
	int GetCurrentScore();

	//function for score
	UFUNCTION(BlueprintPure, Category = "Score")
	int GetScore();

	//Function to update the character score
	UFUNCTION(BlueprintCallable, Category = "Score")
	void UpdateScore(int ScoreChange);

	//function for current lives
	UFUNCTION(BlueprintPure, Category = "Lives")
	int GetCurrentLives();

	//function for current score
	UFUNCTION(BlueprintPure, Category = "Livea")
		int GetLives();

	//Function to update the character lives
	UFUNCTION(BlueprintCallable, Category = "Lives")
		void UpdateLives(int LivesChange);

	//Amount of lives
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lives")
		int Lives;

	

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	

	//Player Score
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int Score;

	//Called when the player collides with pickups
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	void CollectPickups();

private:
	UPROPERTY(VisibleAnywhere, Category = "Score")
		int CurrentScore;
	UPROPERTY(VisibleAnywhere, Category = "Lives")
		int CurrentLives;
public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	//returns the collection sphere
	FORCEINLINE class USphereComponent* GetCollectionSphere() const { return CollectionSphere; }

	

};

