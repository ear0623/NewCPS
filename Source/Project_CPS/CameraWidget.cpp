// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraWidget.h"

void UCameraWidget::NativeConstruct()
{
	SetOn = false;
}

void UCameraWidget::Setvisible()
{
	if (SetOn == false)
	{
		SetOn = true;
		SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		SetOn = false;
		SetVisibility(ESlateVisibility::Collapsed);
	}
}
