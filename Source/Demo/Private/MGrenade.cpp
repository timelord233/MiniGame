// Fill out your copyright notice in the Description page of Project Settings.


#include "MGrenade.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
AMGrenade::AMGrenade()
{
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->InitSphereRadius(10.f);
	CollisionComponent->SetSimulatePhysics(true);
	//	CollisionComponent->SetCollisionProfileName("Projectile");
	RootComponent = CollisionComponent;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SkeletalMeshComponent->SetupAttachment(CollisionComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->UpdatedComponent = RootComponent;
	ProjectileMovementComponent->InitialSpeed = 2000.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->bForceSubStepping = true;

	FuzeTime = 0.7f;
	ExplosionDamage = 100.f;
	ExplosionRadius = 250.f;

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComp"));
	RadialForceComp->SetupAttachment(RootComponent);
	RadialForceComp->Radius = ExplosionRadius;
	RadialForceComp->bImpulseVelChange = true;
	RadialForceComp->bAutoActivate = false;
	RadialForceComp->bIgnoreOwningActor = true;

	SetReplicates(true);
	SetReplicateMovement(true);
}

// Called when the game starts or when spawned
void AMGrenade::BeginPlay()
{
	Super::BeginPlay();

	AActor* MyOwner = GetInstigator();
	if (MyOwner)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FVector Impulse = EyeRotation.Vector() *  1000;
		CollisionComponent->AddImpulse(Impulse);
	}
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMGrenade::OnExplosion, FuzeTime);
}

void AMGrenade::OnExplosion()
{
	// Apply Explosion damage
	AController* Controller = GetInstigator() ? GetInstigator()->GetInstigatorController() : nullptr;
	const bool bDamageApplied = UGameplayStatics::ApplyRadialDamage(GetWorld(), ExplosionDamage, GetActorLocation(), ExplosionRadius, DamageTypeClass, TArray<AActor*>(), this, Controller);
	UE_LOG(LogTemp, Log, TEXT("ASGrenade::OnExplosion: bDamageApplied=%d"), bDamageApplied);

	if (GetLocalRole() == ROLE_Authority)
	{
		MulticastPlayEffect();

		MakeNoise(1.0f, GetInstigator()); 

		Destroy();
	}
}

void AMGrenade::MulticastPlayEffect_Implementation()
{
	UGameplayStatics::PlaySound2D(GetWorld(), ExplosionSound);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
	RadialForceComp->FireImpulse();
}
