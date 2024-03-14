// Fill out your copyright notice in the Description page of Project Settings.


#include "CPSHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.h"
#include "USideSecondWidget.h"
#include "USideFirsetWidget.h"
#include "Components/ListView.h"




ACPSHUD::ACPSHUD()
{

}

void ACPSHUD::BeginPlay()
{
	
	if (ClassOfWidget != NULL)
	{
		ClassWidget = Cast<UUserWidget>(ClassOfWidget);
		ClassWidget = CreateWidget(GetWorld(), ClassOfWidget);
		ClassWidget->AddToViewport();
	}

	MainWidget = Cast<UMainWidget>(ClassWidget);
}

void ACPSHUD::GetCurrentDay(UTextBlock* Day)
{
	FDateTime CurrentDateTime = FDateTime::Now();
	FString Date = CurrentDateTime.ToString(TEXT("%m/%d/%Y"));
	FString DayOfWeek = CurrentDateTime.ToString(TEXT("%A"));
	FString Time = CurrentDateTime.ToString(TEXT("%H:%M"));

	if (Day != nullptr)
	{
		FString Day_Local =  Date + "  " + DayOfWeek + "  " + Time;
		Day->SetText(FText::FromString(Day_Local));
	}
	
}

UUserWidget* ACPSHUD::GetClassWidget() const
{
	return ClassWidget;
}

void ACPSHUD::ConnectTest(int64 idnumber, FString datanamestring, int64 datavalueNumber, int64 vcidNumber, FString vcnameNumber, int64 typeNumber)
{
	ItemName.Add(datanamestring);
	if (MainWidget)
	{	
		MainWidget->GetWBP_USideSecondWidget()->SetListView(idnumber, datanamestring, datavalueNumber, vcidNumber, vcnameNumber, typeNumber);
		MainWidget->GetWBP_USideFirstWidget()->SetListView(idnumber, datanamestring, datavalueNumber, vcidNumber, vcnameNumber, typeNumber);
	}
}


