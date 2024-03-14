// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"
#include "Components/Button.h"
#include "UOptionWidget.h"
#include "UPopUpWidget.h"
#include "CameraWidget.h"

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	Option_Button->OnClicked.AddDynamic(this, &UMainWidget::SetBlind);
	Exit->OnClicked.AddDynamic(this, &UMainWidget::SetPopUpWidget_Exit);
	Cmera_Button->OnClicked.AddDynamic(this, &UMainWidget::SetSub_Camera);
}

void UMainWidget::SetBlind()
{
	OptionBox->SetVisibility(ESlateVisibility::Visible);
	PopUp->SetVisibility(ESlateVisibility::Collapsed);
	Camera->SetVisibility(ESlateVisibility::Collapsed);
}

void UMainWidget::SetPopUpWidget_Exit()
{
	OptionBox->SetVisibility(ESlateVisibility::Collapsed);
	PopUp->SetVIsible(ESlateVisibility::Visible,0);
	Camera->SetVisibility(ESlateVisibility::Collapsed);
}

void UMainWidget::SetDefault()
{
	OptionBox->SetVisibility(ESlateVisibility::Collapsed);
	PopUp->SetVisibility(ESlateVisibility::Collapsed);
	Camera->SetVisibility(ESlateVisibility::Collapsed);
	
}

void UMainWidget::SetSub_Camera()
{
	OptionBox->SetVisibility(ESlateVisibility::Collapsed);
	PopUp->SetVisibility(ESlateVisibility::Collapsed);
	Camera->Setvisible();
}

UUSideSecondWidget* UMainWidget::GetWBP_USideSecondWidget() const
{
	return WBP_USideSecondWidget;
}

UUSideFirsetWidget* UMainWidget::GetWBP_USideFirstWidget() const
{
	return  WBP_USideFirsetWidget;
}

