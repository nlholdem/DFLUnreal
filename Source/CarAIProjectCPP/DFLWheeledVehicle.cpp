// Fill out your copyright notice in the Description page of Project Settings.

#include "DFLWheeledVehicle.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/CoreUObject/Public/UObject/Object.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"

ADFLWheeledVehicle::ADFLWheeledVehicle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Camera = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Camera"));
//	ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> RenderTargetAsset(TEXT("/Game/MyRenderTarget"));
	//here you need to have prepared MyLittleRenderTarget asset, type RenderTarget2D. You can have one for many actors, it is duplicated. What is not resolved by me: i don't know if it is stable solution or it will make crash after many calls

//	RenderTarget = DuplicateObject(RenderTargetAsset.Object, NULL);
//	RenderTarget->InitAutoFormat(1024, 1024);
//	Camera->TextureTarget = RenderTarget;

	UE_LOG(LogTemp, Warning, TEXT("Constructing DFL_Vehicle!!"));

}

// Called when the game starts or when spawned
void ADFLWheeledVehicle::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADFLWheeledVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




