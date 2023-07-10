// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PTRHAnimInstance.generated.h"


/**
 * 
 */
UCLASS()
class PTRH_CGS_API UPTRHAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UPTRHAnimInstance();

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class APRHCharacter* TRHCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	class UCharacterMovementComponent* TRHCharacterMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	float GroundSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	float IsFalling;

	void PlayAttackMontage();
	void JumpToAttackMontageSection(int32 NewSection);

};
