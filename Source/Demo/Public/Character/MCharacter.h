// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class AMWeapon;
class UMHealthComponent;
class AMGrenade;

UCLASS()
class DEMO_API AMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void BeginCrouch();

	void EndCrouch();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components");
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components");
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components");
	UMHealthComponent* HealthComp;

	bool bWantsToZoom;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float ZoomedFOV;

	UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.1, ClampMax = 100))
	float ZoomInterSpeed;

	float DefaultFOV;

	UFUNCTION(BlueprintCallable, Category = "Player")
	void BeginZoom();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void EndZoom();

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	AMWeapon* CurrentWeapon;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TSubclassOf<AMWeapon> StarterWeaponClass;

	UPROPERTY(VisibleDefaultsOnly,Category = "Player")
	FName WeaponAttachSocketName;

	UFUNCTION()
	void OnHealthChanged(UMHealthComponent* HealthComponent, float Heath, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	bool bDied;

	UPROPERTY(Replicated)
	AMGrenade* CurrentGrenade;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	TSubclassOf<AMGrenade> StarterGrenadeClass;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	FVector GrenadeOffset;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FVector GetPawnViewLocation() const override;
    
    UFUNCTION(BlueprintCallable,Category = "Player")
    void StartFire();

    UFUNCTION(BlueprintCallable,Category = "Player")
    void StopFire();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void ThrowGrenade();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerThrowGrenade();
};
