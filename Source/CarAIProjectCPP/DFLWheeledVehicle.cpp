// Fill out your copyright notice in the Description page of Project Settings.

#include "DFLWheeledVehicle.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/CoreUObject/Public/UObject/Object.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"

ADFLWheeledVehicle::ADFLWheeledVehicle()
{


	int nFiltersInput = 10;
	int nFiltersHidden = 10;
	int nNeuronsHidden[] = { 10,10 };

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> RenderTargetAsset(TEXT("/Game/Textures/CameraFeed"));
	RenderTarget = RenderTargetAsset.Object;
	deep_fbl = new DeepFeedbackLearning(2, nNeuronsHidden, 2, 1, nFiltersInput, nFiltersHidden, 100, 200);

	UE_LOG(LogTemp, Warning, TEXT("Constructing DFL_Vehicle!!"));


}

// Called when the game starts or when spawned
void ADFLWheeledVehicle::BeginPlay()
{
	float avgRed, avgGreen, avgBlue;
	avgRed = avgGreen = avgBlue = 0.0;

	Super::BeginPlay();

//	Camera->TextureTarget = RenderTarget;

	int X = RenderTarget->GetSurfaceHeight();
	int Y = RenderTarget->GetSurfaceWidth();
	GLog->Logf(TEXT("Size: %d %d"), X, Y);
	Texture2D = RenderTarget->ConstructTexture2D(this, FString("Tex2D"), EObjectFlags::RF_NoFlags);

}

// Called every frame
void ADFLWheeledVehicle::Tick(float DeltaTime)
{
	float avgRed, avgGreen, avgBlue;
	avgRed = avgGreen = avgBlue = 0.0;

	Super::Tick(DeltaTime);

	//unfortunately we seem to need to construct the texture per frame - need to investigate if there 
	// are more efficients ways round this. 
	Texture2D = RenderTarget->ConstructTexture2D(this, FString("Tex2D"), EObjectFlags::RF_NoFlags);
	Texture2D->UpdateResource();
	int xx = Texture2D->GetSizeX();
	int yy = Texture2D->GetSizeY();
	GLog->Logf(TEXT("Texture size: %d %d"), xx, yy);

	FTexturePlatformData *Data = Texture2D->PlatformData;

	EPixelFormat Format = Data->PixelFormat;
	//format of pixel is PFloatRGBA

	int size = Data->Mips[0].BulkData.GetElementSize();
	int N = Data->Mips[0].BulkData.GetElementCount();

	const void *Table = Data->Mips[0].BulkData.LockReadOnly();
	Data->Mips[0].BulkData.Unlock();

	const uint16 *Tab2 = StaticCast<const uint16*>(Table);
	//Quick sanity check: show the avg pixel colour:
	for (int i = 0; i<xx; i++)
		for (int j = 0; j < yy; j++) {
			int k = 4 * (i*yy + j);
			int R = Tab2[k];
			int G = Tab2[k + 1];
			int B = Tab2[k + 2];
			int A = Tab2[k + 3];
			avgRed += (float)R / (256.0 * (float)xx * (float)yy);
			avgGreen += (float)G / (256.0 * (float)xx * (float)yy);
			avgBlue += (float)B / (256.0 * (float)xx * (float)yy);
		}
	GLog->Logf(TEXT("avgRed: %f avgGreen: %f avgBlue: %f "), avgRed, avgGreen, avgBlue);


}




