// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NavigationObjectBase.h"
#include "MonsterStart.generated.h"

UCLASS()
class DEMO_API AMonsterStart : public ANavigationObjectBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonsterStart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Object)
	FName MonsterStartTag;
};
