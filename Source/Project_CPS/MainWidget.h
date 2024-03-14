// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

class UHorizontalBox;
class UImage;
class UTextBlock;
class UButton;
class UUOptionWidget;
class UUPopUpWidget;
class UCameraWidget;
class UUSideSecondWidget;
class UUSideFirsetWidget;

/**
 * 
 */


UCLASS()
class PROJECT_CPS_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget),meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHorizontalBox> Head;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UImage> Logo;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UTextBlock> SystemName;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UTextBlock> Day;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> Option_Button;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> Exit;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UUOptionWidget> OptionBox;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UUPopUpWidget> PopUp;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> Cmera_Button;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraWidget> Camera;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UUSideSecondWidget> WBP_USideSecondWidget;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UUSideFirsetWidget> WBP_USideFirsetWidget;

public:
	UFUNCTION()
	virtual void NativeConstruct() override;
	UFUNCTION()
	void SetBlind();
	UFUNCTION()
	void SetPopUpWidget_Exit();

	UFUNCTION(BlueprintCallable)
	void SetDefault();

	UFUNCTION()
	void SetSub_Camera();

	UFUNCTION(BlueprintCallable, Category = "UI")
	UUSideSecondWidget* GetWBP_USideSecondWidget() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	UUSideFirsetWidget* GetWBP_USideFirstWidget() const;

};
