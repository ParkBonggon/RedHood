// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "State.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PTRH_CGS_API UState : public UActorComponent
{
	GENERATED_BODY()

public:	
	UState();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HP");
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "HP");
	float MaxHealth;

	void Health();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
