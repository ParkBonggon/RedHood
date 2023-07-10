#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PTRHAnimInstance.generated.h"


/**
 * 
 */
DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);

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

	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnAttackHitCheckDelegate  OnAttackHitCheck;

private:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* AttackMontage;

	UFUNCTION()
		void AnimNotify_AttackHitCheck();

	UFUNCTION()
		void AnimNotify_NextAttackCheck();

	FName GetAttackMontageSectionName(int32 Section);

};
