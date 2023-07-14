#include "PTRHAnimInstance.h"
#include "PTRH_CGS/PRHCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Animation/AnimInstance.h"


UPTRHAnimInstance::UPTRHAnimInstance()
{
	static ConstructorHelpers::FObjectFinder <UAnimMontage> ATTACK_MONTAGE
	(TEXT("/Game/Asset/RedHood/HuntCharacter/Animation/Attack/AM_Attack.AM_Attack"));

	if (ATTACK_MONTAGE.Succeeded())
		AttackMontage = ATTACK_MONTAGE.Object;
};

void UPTRHAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	TRHCharacter = Cast<APRHCharacter>(TryGetPawnOwner());

	if (TRHCharacter)
	{
		TRHCharacterMovement = TRHCharacter->GetCharacterMovement();
	}

}

void UPTRHAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	TRHCharacter = Cast<APRHCharacter>(TryGetPawnOwner());
	if (TRHCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(TRHCharacterMovement->Velocity);
		IsFalling = TRHCharacter->GetVelocity().Z;
	}
}

void UPTRHAnimInstance::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.0f);
}

void UPTRHAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

FName UPTRHAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}
