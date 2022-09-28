// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/MWeapon.h"
#include "MProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API AMProjectileWeapon : public AMWeapon
{
	GENERATED_BODY()

protected:
	virtual void Fire() override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "ProjectileWeapon")
	TSubclassOf<AActor>  ProjectileClass;

};
