
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PRHCharacter.generated.h"

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedSwordAndShild UMETA(DisplayName = "Equipped Sword And Shild"),
	ECS_EquippedBow UMETA(DisplayName = "Equipped Bow")
};

UCLASS()
class PTRH_CGS_API APRHCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APRHCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Jump() override;
	
	FORCEINLINE void SetOverlappingItem(class APItem* Item) { OverlappingItem = Item; }

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "State")
	bool IsFalling;
	
	void PlayEquipMontage(FName SectionName);
	bool CanDisarm();
	bool CanArm();

protected:

	virtual void BeginPlay() override;

	//input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputMappingContext* RedHoodContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputAction* EquipAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputAction* AttackAction;

	void Move(const FInputActionValue& Value);

	void Equip();

	void Attack();

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	void AttackStartComboState();
	void AttackEndComboState();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		bool IsAttacking;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		bool CanNextCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		bool IsComboInputOn;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		int32 CurrentCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Attack", Meta = (AllowPrivateAccess = true))
		int32 MaxCombo;

	UPROPERTY()
	class UPTRHAnimInstance* RHAnim;

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;


private:

	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleInstanceOnly)
		class APItem* OverlappingItem;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
		class APWeapon* EquippedWeapon;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
		UAnimMontage* EquipMontage;


};
