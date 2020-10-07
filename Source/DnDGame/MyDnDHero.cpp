// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDnDHero.h"

//default constructor
AMyDnDHero::AMyDnDHero()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CharacterVals.Strength = CharacterVals.Strength + 6;
	CharacterVals.Charisma = CharacterVals.Charisma + 2;
	CharacterVals.Constitution = CharacterVals.Constitution + 10;
	CharacterVals.Dexterity = CharacterVals.Dexterity + 2;
	CharacterVals.Inteligence = CharacterVals.Inteligence + 2;
	CharacterVals.Wisdow = CharacterVals.Wisdow  + 2;

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialAsset0(TEXT("/Game/Materials/Pawn/MI_HeroHead.MI_HeroHead"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialAsset1(TEXT("/Game/Materials/Pawn/MI_HeroBody.MI_HeroBody"));
	

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
void AMyDnDHero::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyDnDHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyDnDHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}