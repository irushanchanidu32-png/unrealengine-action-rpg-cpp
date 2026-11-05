// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTypes.h"
#include "new_gameAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class NEW_GAME_API Unew_gameAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class Anew_gameCharacter* new_gameCharacter;

	UPROPERTY(BlueprintReadOnly , Category = Movement)
	class UCharacterMovementComponent* new_gameCharacterMovement;

	UPROPERTY(BluePrintReadOnly , Category = Movement)
	float Groundspeed;

	UPROPERTY(BluePrintReadOnly, Category = Movement)
	bool IsFalling;
	
	UPROPERTY(BlueprintReadOnly , Category = "Movement | Character State")
	ECharacterState CharacterState;
};
