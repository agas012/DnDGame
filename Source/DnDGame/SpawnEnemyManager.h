// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyDnDHero.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnEnemyManager.generated.h"

UCLASS()
class DNDGAME_API ASpawnEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
