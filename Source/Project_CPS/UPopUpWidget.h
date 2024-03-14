// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UPopUpWidget.generated.h"


class UTextBlock;
class UButton;
/**
 * 
 */
UENUM()
enum class OptionType : uint8
{
	Exit UMETA(DisplayName = "EXIT"),
	Warning_Alarm UMETA(DisplayName = "WARNING"),
	Warning_RangeOver UMETA(DisplayName = "WARNING")
};

UCLASS()
class PROJECT_CPS_API UUPopUpWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UTextBlock> Header;
	
	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UTextBlock> Input;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> Yes;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> Yes_Senter;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> No;

public:
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	OptionType Optiontype;
public:
	UFUNCTION()
	virtual void NativeConstruct() override;

	UFUNCTION()
	void SetVIsible(ESlateVisibility Eslatevisibility,int64 EnumNumber);

	UFUNCTION()
	void Quit();

	UFUNCTION()
	void Cancle();

};
