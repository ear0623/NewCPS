// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UBottomBar.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class PROJECT_CPS_API UUBottomBar : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> Home_Button;

public:
	void SettingInitValue();
	
};
