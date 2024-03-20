// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomActor.h"
#include "APController.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"

// Sets default values
ACustomActor::ACustomActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SCene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SCene->SetupAttachment(RootComponent);

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Targetmesh"));
	TargetMesh->SetupAttachment(SCene);

	TargetSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletalmesh"));
	TargetSkeletalMesh->SetupAttachment(SCene);


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

	if (this->IDName == name && TargetMesh != nullptr)
	{
		if (TargetMesh->bRenderCustomDepth == true)
		{
			TargetMesh->SetRenderCustomDepth(false);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("asd")));
		}
		else
		{
			TargetMesh->SetRenderCustomDepth(true);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("false")));
		}
	}
	else if (this->IDName == name && TargetSkeletalMesh != nullptr)
	{
		if (TargetSkeletalMesh->bRenderCustomDepth == true)
		{
			TargetSkeletalMesh->SetRenderCustomDepth(false);
		}
		else
		{
			TargetSkeletalMesh->SetRenderCustomDepth(true);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("false")));
		}
	}
	else if(this->IDName != name)
	{
		if (TargetMesh->bRenderCustomDepth == true&& TargetMesh != nullptr)
		{
			TargetMesh->SetRenderCustomDepth(false);
			
		}
	}
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("SetLineOnOff %s"), TargetMesh->bRenderCustomDepth));
}

void ACustomActor::SetLineOnOff_Innumber(int64 Id)
{
	if (this->ID == Id && TargetMesh != nullptr)
	{
		if (TargetMesh->bRenderCustomDepth == true)
		{
			TargetMesh->SetRenderCustomDepth(false);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("asd")));
		}
		else
		{
			TargetMesh->SetRenderCustomDepth(true);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("false")));
		}
	}
	else if(this->ID != Id)
	{
		if (TargetMesh->bRenderCustomDepth == true && TargetMesh != nullptr)
		{
			TargetMesh->SetRenderCustomDepth(false);

		}
	}
}

void ACustomActor::SetLineOnOff_Child(int64 Id)
{
	if (this->ID == Id && TargetMesh != nullptr)
	{
		if (TargetMesh->bRenderCustomDepth == true)
		{
			TargetMesh->SetRenderCustomDepth(false);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("asd")));
		}
		else
		{
			TargetMesh->SetRenderCustomDepth(true);
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("false")));
		}
	}
	else if (this->ID != Id)
	{
		if (TargetMesh->bRenderCustomDepth == true && TargetMesh != nullptr)
		{
			TargetMesh->SetRenderCustomDepth(false);

		}
	}
}

