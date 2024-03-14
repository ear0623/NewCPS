// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPS_GameMode.generated.h"

class UHTTPObject;
/**
 * 
 */
UCLASS()
class PROJECT_CPS_API ACPS_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
public:

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UObject> DataObject;
	
};
