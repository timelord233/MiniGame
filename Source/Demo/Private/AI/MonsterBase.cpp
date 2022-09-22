// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MonsterBase.h"
#include "Components/MHealthComponent.h"

// Sets default values
AMonsterBase::AMonsterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HealthComp = CreateDefaultSubobject<UMHealthComponent>(TEXT("HealthComp"));
}

// Called when the game starts or when spawned
void AMonsterBase::BeginPlay()
{
	Super::BeginPlay();
	HealthComp->OnHealthChanged.AddDynamic(this, &AMonsterBase::OnHealthChanged);
}

void AMonsterBase::OnHealthChanged(UMHealthComponent* HealthComponent, float Heath, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{

}

// Called every frame
void AMonsterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMonsterBase::Attack()
{
	
}

