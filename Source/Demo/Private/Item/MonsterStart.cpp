// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/MonsterStart.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMonsterStart::AMonsterStart()
{
	GetCapsuleComponent()->InitCapsuleSize(40.0f, 92.0f);
	GetCapsuleComponent()->SetShouldUpdatePhysicsVolume(false);
}

// Called when the game starts or when spawned
void AMonsterStart::BeginPlay()
{
	Super::BeginPlay();
	
}


