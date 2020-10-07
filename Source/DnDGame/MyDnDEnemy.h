// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "CoreMinimal.h"
#include "DnDCharacter.h"
#include "MyDnDEnemy.generated.h"

/**
 * 
 */
UCLASS()
class DNDGAME_API AMyDnDEnemy : public ADnDCharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AMyDnDEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
