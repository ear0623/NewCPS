// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UOptionWidget.generated.h"

class UBorder;
class UComboBoxString;
class USlider;
class UButton;
/**
 * 
 */


UCLASS()
class PROJECT_CPS_API UUOptionWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBorder> BorderSize;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UComboBoxString> Menubar_resolution;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USlider> Menubar_Sound;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UComboBoxString> Menubar_Window;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> ReSet;

protected:

public:
	UFUNCTION()
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SettingResolution(int64 Width, int64 Height, bool bFullScreen);


};
