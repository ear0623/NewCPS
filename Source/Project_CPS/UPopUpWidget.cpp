// Fill out your copyright notice in the Description page of Project Settings.


#include "UPopUpWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetSystemLibrary.h"

void UUPopUpWidget::NativeConstruct()
{
	Yes->SetVisibility(ESlateVisibility::Hidden);
	Yes_Senter->SetVisibility(ESlateVisibility::Hidden);
	No->SetVisibility(ESlateVisibility::Hidden);
}

void UUPopUpWidget::SetVIsible(ESlateVisibility Eslatevisibility, int64 EnumNumber)
{
	this->SetVisibility(Eslatevisibility);
	if (Eslatevisibility == ESlateVisibility::Visible)
	{
		switch (Optiontype)
		{
		case OptionType::Exit:
			Yes->SetVisibility(ESlateVisibility::Visible);
			Yes_Senter->SetVisibility(ESlateVisibility::Hidden);
			No->SetVisibility(ESlateVisibility::Visible);
			Header->SetText(FText::FromString("SHUTTING DOWN"));
			Input->SetText(FText::FromString("QUIT"));
			Yes->OnClicked.AddDynamic(this, &UUPopUpWidget::Quit);
			No->OnClicked.AddDynamic(this, &UUPopUpWidget::Cancle);
			break;

		case OptionType::Warning_Alarm:
			Yes->SetVisibility(ESlateVisibility::Hidden);
			Yes_Senter->SetVisibility(ESlateVisibility::Visible);
			No->SetVisibility(ESlateVisibility::Hidden);
			Header->SetText(FText::FromString("WARNING"));
			Input->SetText(FText::FromString("Stop and run the alarm"));
			Yes_Senter->OnClicked.AddDynamic(this, &UUPopUpWidget::Cancle);
			break;

		case OptionType::Warning_RangeOver:
			Yes->SetVisibility(ESlateVisibility::Hidden);
			Yes_Senter->SetVisibility(ESlateVisibility::Visible);
			No->SetVisibility(ESlateVisibility::Hidden);
			Header->SetText(FText::FromString("WARNING"));
			Input->SetText(FText::FromString("The upper and lower bounds cannot be the same"));
			Yes_Senter->OnClicked.AddDynamic(this, &UUPopUpWidget::Cancle);
			break;
		default:
			break;
		}
	}
}

void UUPopUpWidget::Quit()
{
	TObjectPtr<APlayerController> PlayerController;
	UKismetSystemLibrary::QuitGame(GetWorld(),PlayerController,EQuitPreference::Quit,true);
}

void UUPopUpWidget::Cancle()
{
	this->SetVisibility(ESlateVisibility::Collapsed);
}
