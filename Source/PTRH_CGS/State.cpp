// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"

// Sets default values for this component's properties
UState::UState()
{
	PrimaryComponentTick.bCanEverTick = true;

	CurrentHealth;
}


void UState::Health()
{
	if (CurrentHealth)
	{

	}
}

// Called when the game starts
void UState::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UState::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

