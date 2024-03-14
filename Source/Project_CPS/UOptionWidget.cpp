// Fill out your copyright notice in the Description page of Project Settings.


#include "UOptionWidget.h"
#include "Components/ComboBoxString.h"
#include "GameFramework/GameUserSettings.h"


void UUOptionWidget::NativeConstruct()
{

}

void UUOptionWidget::SettingResolution(int64 Width, int64 Height, bool bFullScreen)
{
	UE_LOG(LogTemp, Warning, TEXT("%d  ,  %d"), Width, Height);
	TObjectPtr<UGameUserSettings> Setting = GetMutableDefault<UGameUserSettings>();

	if (Setting)
	{
		Setting->SetScreenResolution(FIntPoint(Width, Height));
		Setting->SetFullscreenMode(bFullScreen ? EWindowMode::WindowedFullscreen : EWindowMode::Windowed);
		Setting->ApplySettings(false);
		Setting->SaveSettings();
	}
}


