// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MGrenade.generated.h"

UCLASS()
class DEMO_API AMGrenade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMGrenade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/** Sphere collision component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* CollisionComponent;

	/** Static Mesh component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USkeletalMeshComponent* SkeletalMeshComponent;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class URadialForceComponent* RadialForceComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
	UParticleSystem* ExplosionEffect;

	// Sound to play on explosion
	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	USoundBase* ExplosionSound;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float FuzeTime;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float ExplosionDamage;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float ExplosionRadius;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	TSubclassOf<UDamageType> DamageTypeClass;

	void OnExplosion();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastPlayEffect();
};
