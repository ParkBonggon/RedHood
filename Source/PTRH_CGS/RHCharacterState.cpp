#include "RHCharacterState.h"

URHCharacterState::URHCharacterState()
{
	PrimaryComponentTick.bCanEverTick = true;

	MaxHP = 100.0f;
}

bool URHCharacterState::IncreaseHP(float Value)
{
	if (CurrentHP == MaxHP) {
		return false;
	}
	else {
		CurrentHP += Value;
		if (CurrentHP > MaxHP) CurrentHP = MaxHP;
	}
	return true;
}

bool URHCharacterState::DecreaseHP(float Value)
{
	if (CurrentHP > 0.f)
	{
		CurrentHP -= Value;
		bIsDead = false;
		if (CurrentHP <= 0.f)
		{
			bIsDead = true;
		}
	}
	else {

		return false;
	}
	return true;
}

void URHCharacterState::BeginPlay()
{
	Super::BeginPlay();

	CurrentHP = MaxHP;
}

void URHCharacterState::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

