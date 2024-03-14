// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CameraWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_CPS_API UCameraWidget : public UUserWidget
{
	GENERATED_BODY()


private:

	bool SetOn;
public:
	UFUNCTION()
	virtual void NativeConstruct() override;

	UFUNCTION()
	void Setvisible();
	
};
