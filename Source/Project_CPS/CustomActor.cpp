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

	TargetSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletalmesh"));
	TargetSkeletalMesh->SetupAttachment(RootComponent);
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

void ACustomActor::SetLineOnOff(FName name)
{
	if (this->ActorHasTag(name)&& TargetMesh != nullptr)
	{
		if (TargetMesh->bRenderCustomDepth == true)
		{
			TargetMesh->SetRenderCustomDepth(false);

			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, SourceFileTagName().ToString());
		}
		else
		{
			TargetMesh->SetRenderCustomDepth(true);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("false")));
		}
	}
	else if (this->ActorHasTag(name)&& TargetSkeletalMesh != nullptr)
	{
		if (TargetSkeletalMesh->bRenderCustomDepth == true)
		{
			TargetSkeletalMesh->SetRenderCustomDepth(false);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, SourceFileTagName().ToString());
		}
		else
		{
			TargetSkeletalMesh->SetRenderCustomDepth(true);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("false")));
		}
	}
	else if(!this->ActorHasTag(name))
	{
		if (TargetMesh->bRenderCustomDepth == true&& TargetMesh != nullptr)
		{
			TargetMesh->SetRenderCustomDepth(false);
			
		}
		/*if (TargetSkeletalMesh->bRenderCustomDepth == true&& TargetSkeletalMesh !=nullptr)
		{
			TargetSkeletalMesh->SetRenderCustomDepth(false);
		}*/
	}
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("SetLineOnOff %s"), TargetMesh->bRenderCustomDepth));
}

