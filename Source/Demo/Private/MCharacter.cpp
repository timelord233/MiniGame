// Fill out your copyright notice in the Description page of Project Settings.


#include "MCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/MHealthComponent.h"
#include "MWeapon.h"
#include "../Demo.h"
#include "Net/UnrealNetwork.h"
#include "MGrenade.h"

// Sets default values
AMCharacter::AMCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Ignore);

	HealthComp = CreateDefaultSubobject<UMHealthComponent>(TEXT("HealthComp"));

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	ZoomedFOV = 65;
	ZoomInterSpeed = 20;
	GrenadeOffset = FVector(200, 0, 0);

	WeaponAttachSocketName = "WeaponSocket";
}

// Called when the game starts or when spawned
void AMCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	DefaultFOV = CameraComp->FieldOfView;
	HealthComp->OnHealthChanged.AddDynamic(this, &AMCharacter::OnHealthChanged);

	if (GetLocalRole() == ROLE_Authority) 
	{
		//Spawn a default weapon
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		CurrentWeapon = GetWorld()->SpawnActor<AMWeapon>(StarterWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
		if (CurrentWeapon)
		{
			CurrentWeapon->SetOwner(this);
			CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponAttachSocketName);
		}
	}

}

void AMCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void AMCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}

void AMCharacter::BeginCrouch()
{
	Crouch();
}

void AMCharacter::EndCrouch()
{
	UnCrouch();
}

void AMCharacter::BeginZoom()
{
	bWantsToZoom = true;
}

void AMCharacter::EndZoom()
{
	bWantsToZoom = false;
}

void AMCharacter::StartFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StartFire();
	}
}

void AMCharacter::StopFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StopFire();
	}
}

void AMCharacter::ThrowGrenade()
{
	if (GetLocalRole() < ROLE_Authority)
	{
		ServerThrowGrenade();
		return;
	}

	if (StarterGrenadeClass)
	{
		FVector SpawnLocation = GetActorLocation() + GetControlRotation().RotateVector(GrenadeOffset);
		//	FRotator MuzzleRotation = SkeletalMeshComponent->GetSocketRotation(MuzzleSocketName); // NOTE: this has a fixed zero Pitch for now, use ViewpointOrientation instead
		FVector ViewpointLocation;
		FRotator ViewpointOrientation;
		GetActorEyesViewPoint(ViewpointLocation, ViewpointOrientation);

		// Set Spawn Collision Handling Override
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.Instigator = this; // required to associate the projectile to the Pawn

		// Spawn a Grenade
		CurrentGrenade = GetWorld()->SpawnActor<AMGrenade>(StarterGrenadeClass, SpawnLocation, ViewpointOrientation, SpawnParams);
	}
}

void AMCharacter::ServerThrowGrenade_Implementation()
{
	ThrowGrenade();
}

bool AMCharacter::ServerThrowGrenade_Validate()
{
	return true;
}

void AMCharacter::OnHealthChanged(UMHealthComponent* HealthComponent, float Heath, float HealthDelta, const class UDamageType* DamageType,
	class AController* InstigatedBy, AActor* DamageCauser)
{
	if (Heath <= 0.0f && !bDied)
	{
		// Die£¡

		bDied = true;
		if (CurrentWeapon)
		{
			CurrentWeapon->Destroy();
		}
		GetMovementComponent()->StopMovementImmediately();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		//DetachFromControllerPendingDestroy();

		SetLifeSpan(2.0f);
	}
}

// Called every frame
void AMCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float TargetFOV = bWantsToZoom ? ZoomedFOV : DefaultFOV;
	float NewFOV = FMath::FInterpTo(CameraComp->FieldOfView, TargetFOV, DeltaTime, ZoomInterSpeed);

	CameraComp->SetFieldOfView(NewFOV);
}

// Called to bind functionality to input
void AMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AMCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &AMCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMCharacter::BeginCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMCharacter::EndCrouch);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAction("Zoom", IE_Pressed, this, &AMCharacter::BeginZoom);
	PlayerInputComponent->BindAction("Zoom", IE_Released, this, &AMCharacter::EndZoom);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AMCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AMCharacter::StopFire);

	PlayerInputComponent->BindAction("Grenade", IE_Pressed, this, &AMCharacter::ThrowGrenade);
}

FVector AMCharacter::GetPawnViewLocation() const
{
	if (CameraComp) 
	{
		return CameraComp->GetComponentLocation();
	}

	return Super::GetPawnViewLocation();
}

void AMCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMCharacter, CurrentWeapon);
	DOREPLIFETIME(AMCharacter, bDied);
}