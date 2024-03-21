// Fill out your copyright notice in the Description page of Project Settings.


#include "HTTPActor.h"
#include "HTTPObject.h"

// Sets default values
AHTTPActor::AHTTPActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DataObject = CreateDefaultSubobject<UHTTPObject>(TEXT("HTTPobject"));
}

// Called when the game starts or when spawned
void AHTTPActor::BeginPlay()
{
	Super::BeginPlay();

	

	/*if (DataObject != nullptr)
	{
		DataObject->GetHttpData().AddDynamic(this, &AHTTPActor::SetListVuew);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, FString::Printf(TEXT("false")));
	}*/

}

// Called every frame
void AHTTPActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AHTTPActor::SetListVuew(int64 Id, FString DataName, int64 DataValue, int64 VCID, FString VCName, int64 Type)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, DataName);
}

