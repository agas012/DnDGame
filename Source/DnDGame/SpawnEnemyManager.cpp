// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEnemyManager.h"

// Sets default values
ASpawnEnemyManager::ASpawnEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnEnemyManager::BeginPlay()
{
	Super::BeginPlay();

	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	GetWorld()->SpawnActor<AMyDnDHero>(Location, Rotation, SpawnInfo);
	
}

// Called every frame
void ASpawnEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

