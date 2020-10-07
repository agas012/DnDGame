// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DnDCharacter.generated.h"

USTRUCT(BlueprintType)
struct FCharacterSheet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Dexterity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Constitution;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Inteligence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Wisdow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Charisma;

	//default constructor
	FCharacterSheet()
	{
		Strength = 10;
		Dexterity = 10;
		Constitution = 10;
		Inteligence = 10;
		Wisdow = 10;
		Charisma = 10;
	}

};

USTRUCT(BlueprintType)
struct FCharacterDeriv
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxHitPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentHitPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float attack_value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float defence_value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float current_total_defence;

	//default constructor
	FCharacterDeriv()
	{
		MaxHitPoints = 10;
		CurrentHitPoints = MaxHitPoints;
		attack_value = 10;
		defence_value = 10;
		current_total_defence = defence_value;
	}
};

UCLASS()
class DNDGAME_API ADnDCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADnDCharacter();

	//variable to add a static mesh to the class
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	//generic properties of all my characters 
	FCharacterSheet CharacterVals;
	FCharacterDeriv CharacterDeriv;
};
