
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PRHCharacter.generated.h"

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bCanAttack;
	
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

	UPROPERTY()
	class UPTRHAnimInstance* RHAnim;

private:

	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleInstanceOnly)
		class APItem* OverlappingItem;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
		class APWeapon* EquippedWeapon;
};
