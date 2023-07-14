// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PItem.generated.h"


UCLASS()
class PTRH_CGS_API APItem : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	APItem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* ItemMesh;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


private:

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Sphere;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
