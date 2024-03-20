// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "APController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetPostProcessOnOff,FName,name);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetPostProcessOnOff_InNumber, int64, ID);

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
	FRotator Rotation;

	FTimerHandle TimerHandle;
	FTimerHandle TimerHandle_Arm;

public:
	FSetPostProcessOnOff Setpos;
	FSetPostProcessOnOff_InNumber Setpos_i;

public:
	UFUNCTION(BlueprintCallable)
	void InitSetting();

	void InitSetting_Camera();

	void InitSetting_Player_Pos();

	void InitSetting_SprinArm();


	UFUNCTION(BlueprintCallable)
	bool GetHit();

	UFUNCTION(BlueprintCallable)
	void GetClickBTC(UClass* InputClass);

	UFUNCTION(BlueprintCallable)
	void SaveTag(FText name);

	UFUNCTION(BlueprintCallable)
	void SaveId(int64 Id);

	bool CheckNumber(int64 Number);

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "InterpSpeed", meta = (AllowPrivateAccess = "true"))
	float InterSpeed;
};
