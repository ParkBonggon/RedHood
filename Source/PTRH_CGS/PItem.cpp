// Fill out your copyright notice in the Description page of Project Settings.


#include "PItem.h"
#include "Components/SphereComponent.h"
#include "PRHCharacter.h"


// Sets default values
APItem::APItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APItem::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &APItem::OnOverlapBegin);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &APItem::OnEndOverlap);
	
}

// Called every frame
void APItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void APItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APRHCharacter* RHCharacter = Cast<APRHCharacter>(OtherActor);
	if (RHCharacter)
	{
		RHCharacter->SetOverlappingItem(this);
	}
}

void APItem::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString OtherActorName = FString("Ending Overlap with: ") + OtherActor->GetName();
	APRHCharacter* RHCharacter = Cast<APRHCharacter>(OtherActor);
	if (RHCharacter)
	{
		RHCharacter->SetOverlappingItem(nullptr);
	}
}

