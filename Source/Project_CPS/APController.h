// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "APController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetPostProcessOnOff,FName,name);

class UInputMappingContext;
class APlayerPawn;
/**
 * 
 */
UCLASS()
class PROJECT_CPS_API AAPController : public APlayerController
{
	GENERATED_BODY()
	
	AAPController();
private:

public:
	virtual void BeginPlay() override;

	

private:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Enhanced",meta= (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY()
	TObjectPtr<APlayerPawn>MyPlayer;

	FVector Location;

	FTimerHandle TimerHandle;
	FTimerHandle TimerHandle_Arm;

public:
	FSetPostProcessOnOff Setpos;

public:
	UFUNCTION(BlueprintCallable)
	void InitSetting();

	void InitSetting_Camera();

	void InitSetting_Player_Pos();

	void InitSetting_SprinArm();


	UFUNCTION(BlueprintCallable)
	bool GetHit();

	void SaveTag();

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "InterpSpeed", meta = (AllowPrivateAccess = "true"))
	float InterSpeed;
};
