// Fill out your copyright notice in the Description page of Project Settings.


#include "PTRHAnimInstance.h"
#include "PTRH_CGS/PRHCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

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

	if (TRHCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(TRHCharacterMovement->Velocity);
		IsFalling = TRHCharacterMovement->IsFalling();
	}
}