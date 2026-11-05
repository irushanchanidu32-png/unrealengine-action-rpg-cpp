

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "new_gameCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class AItem;
class UAnimMontage;
class AWeapon;





UCLASS()
class NEW_GAME_API Anew_gameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	Anew_gameCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);

	
protected:
	virtual void BeginPlay() override;


	/**
	*callbacks for input*/
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float value);
	void LookUp(float Value);
	void EKeyPressed();
	void Attack();
	/**
	*Play montage functions
	*/
	void PlayAttackMontage();


	UFUNCTION(BlueprintCallable)
	void AttackEnd();

	bool CanAttack();


	void PlayEquipMontage(FName SectionName);
	bool CanDisarm();

	bool CanArm();


	UFUNCTION(BlueprintCallable)
	void Disarm();

	UFUNCTION(BlueprintCallable)
	void Arm();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();
private:


	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;


	UPROPERTY(BluePrintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;


	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere , Category = Hair)
	UGroomComponent* Hair;
	 
	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Eyebrows;



	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	AWeapon* EquippedWeapon;

	/**
	*Animation montages
	*/
	UPROPERTY(EditDefaultsOnly ,  Category = Montages)
	UAnimMontage* AttackMontage;


	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* EquipMontage;
	

public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};
