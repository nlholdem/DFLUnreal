// Fill out your copyright notice in the Description page of Project Settings.

#include "DFLWheeledVehicle.h"

ADFLWheeledVehicle::ADFLWheeledVehicle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
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




