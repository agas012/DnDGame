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

	FVector Location(300.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	for (int i = 0; i < 4; i++)
	{
		AMyDnDEnemy* ptract = GetWorld()->SpawnActor<AMyDnDEnemy>(Location, Rotation, SpawnInfo);
		enemies.push_back(ptract);
		Location.X = Location.X - 150;
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("My Location is: %s"), *enemies[i]->GetActorLocation().ToString()));
		UE_LOG(LogTemp, Warning, TEXT("My Location is: %s"), *enemies[i]->GetActorLocation().ToString());
	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("vector size: %d"), enemies.size()));
	
	int del_idx = 0;
	enemies[del_idx]->Destroy();
	enemies.erase(enemies.begin() + del_idx);

	for (int i = 0; i < enemies.size(); i++)
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("My Location is: %s"), *enemies[i]->GetActorLocation().ToString()));
		UE_LOG(LogTemp, Warning, TEXT("My Location is: %s"), *enemies[i]->GetActorLocation().ToString());
	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("vector size: %d"), enemies.size()));
}

// Called every frame
void ASpawnEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

