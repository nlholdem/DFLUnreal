// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "Runtime/Engine/Classes/Components/SceneCaptureComponent2D.h"
#include "Runtime/Engine/Classes/Engine/TextureRenderTarget2D.h"
#include "deep_feedback_learning/deep_feedback_learning.h"
#include "DFLWheeledVehicle.generated.h"

/**
 * 
 */


UCLASS(Blueprintable)
class CARAIPROJECTCPP_API ADFLWheeledVehicle : public AWheeledVehicle
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties
	ADFLWheeledVehicle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UTextureRenderTarget2D *RenderTarget;
	UTexture2D *Texture2D;
	
protected:
	DeepFeedbackLearning *deep_fbl;
};

