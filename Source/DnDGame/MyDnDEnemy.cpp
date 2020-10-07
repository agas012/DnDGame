// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDnDEnemy.h"

//default constructor
AMyDnDEnemy::AMyDnDEnemy()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CharacterVals.Strength = CharacterVals.Strength + 6;
	CharacterVals.Charisma = CharacterVals.Charisma + 2;
	CharacterVals.Constitution = CharacterVals.Constitution + 10;
	CharacterVals.Dexterity = CharacterVals.Dexterity + 2;
	CharacterVals.Inteligence = CharacterVals.Inteligence + 2;
	CharacterVals.Wisdow = CharacterVals.Wisdow + 2;

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialAsset0(TEXT("/Game/Materials/Pawn/MI_EnemyHead.MI_EnemyHead"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialAsset1(TEXT("/Game/Materials/Pawn/MI_EnemyBody.MI_EnemyBody"));


	if (MaterialAsset0.Succeeded())
	{
		VisualMesh->SetMaterial(0, MaterialAsset0.Object);
	}
	if (MaterialAsset1.Succeeded())
	{
		VisualMesh->SetMaterial(1, MaterialAsset1.Object);
	}
}

// Called when the game starts or when spawned
void AMyDnDEnemy::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyDnDEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyDnDEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}