// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PItem.h"
#include "PWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PTRH_CGS_API APWeapon : public APItem
{
	GENERATED_BODY()

public:
	void Equip(USceneComponent* InParent, FName InSocketName);

protected:


	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

};
