// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HTTPActor.generated.h"

class UHTTPObject;

UCLASS()
class PROJECT_CPS_API AHTTPActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHTTPActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHTTPObject> DataObject;

public:
	UFUNCTION(BlueprintCallable)
	void SetListVuew(int64 Id, FString DataName, int64 DataValue, int64 VCID, FString VCName, int64 Type);

};
