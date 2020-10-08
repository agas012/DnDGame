// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <random>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dices.generated.h"


UCLASS()
class DNDGAME_API ADices : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADices();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	// random decives
	std::uniform_int_distribution<int> dice_six;
	std::uniform_int_distribution<int> dice_twelve;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int throw_dice_six();
	int throw_dice_twelve();
	int diceval;
};
