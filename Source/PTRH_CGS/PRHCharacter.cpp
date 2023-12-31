
#include "PRHCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PItem.h"
#include "PWeapon.h"
#include "Animation/AnimMontage.h"
#include "Components/ArrowComponent.h"




APRHCharacter::APRHCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetupAttachment(RootComponent);
	GetCapsuleComponent()->InitCapsuleSize(25.0f, 93.0f);


	//Camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetCapsuleComponent());
	CameraBoom->TargetArmLength = 700.0f;
	CameraBoom->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 40.0f), FRotator(-15.0f, -90.0f, 0.0f));

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);

	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritYaw = false;
	CameraBoom->bInheritRoll = false;

	//Weapon

	Sword = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sword"));
	Sword->SetupAttachment(GetMesh());

	SwordTraceStart = CreateDefaultSubobject<UArrowComponent>(TEXT("Start"));
	SwordTraceStart->SetupAttachment(Sword);

	SwordTraceEnd = CreateDefaultSubobject<UArrowComponent>(TEXT("End"));
	SwordTraceEnd->SetupAttachment(Sword);


	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	UCharacterMovementComponent* const CharactorRotation = GetCharacterMovement();
	if (CharactorRotation)
	{
		CharactorRotation->bOrientRotationToMovement = true;
		CharactorRotation->bUseControllerDesiredRotation = false;
	}

	bCanAttack = true;

}

void APRHCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(APlayerController * PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(RedHoodContext, 0);
		}
	}
}

//Move
void APRHCharacter::Move(const FInputActionValue& Value)
{
	if (bCanAttack)
	{
		if (Controller != nullptr)
		{
			const FVector2D MovementVector = Value.Get<FVector2D>();

			AddMovementInput(FVector(MovementVector.X, 0.f, 0.f));
			AddMovementInput(FVector(0.f, MovementVector.Y, 0.f));
		}
	}
}

// Called every frame
void APRHCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APRHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &APRHCharacter::Move);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APRHCharacter::Jump);
		EnhancedInputComponent->BindAction(EquipAction, ETriggerEvent::Triggered, this, &APRHCharacter::Equip);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &APRHCharacter::Attack);
		EnhancedInputComponent->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &APRHCharacter::Dodge);
	}

}

void APRHCharacter::Jump()
{
	if (bCanAttack)
	{
		Super::Jump();
	}
		
}

void APRHCharacter::Equip()
{
	APWeapon* OverlappingWeapon = Cast<APWeapon>(OverlappingItem);
	if (OverlappingWeapon)
	{
		OverlappingWeapon->Equip(GetMesh(), FName("RightHandWeapon"));
		OverlappingItem = nullptr;
		EquippedWeapon = OverlappingWeapon;
	}
}

void APRHCharacter::Attack()
{
}

void APRHCharacter::Dodge()
{
}
