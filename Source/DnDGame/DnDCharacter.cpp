// Fill out your copyright notice in the Description page of Project Settings.


#include "DnDCharacter.h"

// Sets default values
ADnDCharacter::ADnDCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogClass, Log, TEXT("Hello from Pawn character class"));

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Game/Meshes/Pawn/Pawn.Pawn"));

	
	if (VisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(VisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	}

	CharacterVals.Strength = 10;
	CharacterVals.Charisma = 10;
	CharacterVals.Constitution = 10;
	CharacterVals.Dexterity = 10;
	CharacterVals.Inteligence = 10;
	CharacterVals.Wisdow = 10;

	CharacterDeriv.MaxHitPoints = FMath::RoundHalfFromZero(0.20f * CharacterVals.Strength + 0.60f * CharacterVals.Constitution);
	CharacterDeriv.CurrentHitPoints = CharacterDeriv.MaxHitPoints;

}

// Called when the game starts or when spawned
void ADnDCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADnDCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADnDCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

