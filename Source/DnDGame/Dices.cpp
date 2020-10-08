// Fill out your copyright notice in the Description page of Project Settings.


#include "Dices.h"

// Sets default values
ADices::ADices()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);									
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Game/Meshes/Dices/DiceTwelve.DiceTwelve"));

	if (VisualAsset.Succeeded()) {

		VisualMesh->SetStaticMesh(VisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

	dice_six = std::uniform_int_distribution<int>(1, 6);
	dice_six = std::uniform_int_distribution<int>(1, 12);

}

// Called when the game starts or when spawned
void ADices::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADices::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 30.0f;
	float DeltaRotation = DeltaTime * 50.0f;
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
	diceval = throw_dice_six();
	UE_LOG(LogClass, Log, TEXT("dice value: %d"), diceval);
}

int ADices::throw_dice_six()
{
	return dice_six(engine);
}

int ADices::throw_dice_twelve()
{
	return dice_twelve(engine);
}

