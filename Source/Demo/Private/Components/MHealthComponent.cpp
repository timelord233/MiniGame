// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MHealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "MGameMode.h"
#include "MCharacter.h"
#include "MPlayerState.h"

// Sets default values for this component's properties
UMHealthComponent::UMHealthComponent()
{
	DefaultHealth = 100;
	bIsDead = false;

	SetIsReplicatedByDefault(true);
}


// Called when the game starts
void UMHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwnerRole() == ROLE_Authority)
	{
		AActor* MyOwner = GetOwner();
		if (MyOwner)
		{
			MyOwner->OnTakeAnyDamage.AddDynamic(this, &UMHealthComponent::HandleTakeDamage);
		}
	}
	Health = DefaultHealth;
}

void UMHealthComponent::HandleTakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f || bIsDead)
	{
		return;
	}

	if (DamagedActor!=DamageCauser && IsFriendly(DamagedActor, InstigatedBy->GetPawn())) 
	{
		return;
	}
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	UE_LOG(LogTemp, Log, TEXT("Health Changed: %s"),*FString::SanitizeFloat(Health));

	bIsDead = Health <= 0.0f;

	OnHealthChanged.Broadcast(this, Health, Damage, DamageType, InstigatedBy, DamageCauser);

	if (bIsDead)
	{
		AMGameMode* GM = Cast<AMGameMode>(GetWorld()->GetAuthGameMode());
		if (GM)
		{
			GM->OnActorKilled.Broadcast(GetOwner(), DamageCauser, InstigatedBy);
		}
	}
}

bool UMHealthComponent::IsFriendly(AActor* ActorA, AActor* ActorB)
{
	if (ActorA == nullptr || ActorB == nullptr)
	{
		return true;
	}
	
	AMPlayerState* PlayerStateA = Cast<APawn>(ActorA)->GetPlayerState<AMPlayerState>();
	AMPlayerState* PlayerStateB = Cast<APawn>(ActorB)->GetPlayerState<AMPlayerState>();

	if (PlayerStateA == nullptr || PlayerStateB == nullptr)
	{
		return false;
	}

	return PlayerStateA->TeamNum == PlayerStateB->TeamNum;
}

void UMHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UMHealthComponent, Health);
}

