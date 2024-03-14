// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomActor.h"
#include "APController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACustomActor::ACustomActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Targetmesh"));
	TargetMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACustomActor::BeginPlay()
{
	Super::BeginPlay();

	TObjectPtr<AAPController> APCController = Cast<AAPController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (APCController) 
	{
		APCController->Setpos.AddDynamic(this, &ACustomActor::SetLineOnOff);
	}
}

// Called every frame
void ACustomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACustomActor::SetLineOnOff()
{
	
	if (TargetMesh->bRenderCustomDepth == true)
	{
		TargetMesh->SetRenderCustomDepth(false);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("true")));
	}
	else
	{
		TargetMesh->SetRenderCustomDepth(true);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("false")));
	}
	
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("SetLineOnOff %s"), TargetMesh->bRenderCustomDepth));
}

