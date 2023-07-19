// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RHCharacterState.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PTRH_CGS_API URHCharacterState : public UActorComponent
{
	GENERATED_BODY()

public:	

	URHCharacterState();

	UFUNCTION(BlueprintCallable)
	bool IncreaseHP(float Value);

	UFUNCTION(BlueprintCallable)
	bool DecreaseHP(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HP")
	float CurrentHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HP")
	float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dead")
	bool bIsDead;

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
