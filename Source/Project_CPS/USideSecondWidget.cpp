// Fill out your copyright notice in the Description page of Project Settings.


#include "USideSecondWidget.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "AStructorActor.h"
#include "HTTPObject.h"
#include "Components/ListView.h"
#include "UListWidget.h"
#include "HTTPActor.h"
#include "GameFramework/Actor.h"
#include "Components/TreeView.h"


void UUSideSecondWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Background = Cast<UBorder>(GetWidgetFromName(TEXT("Background")));
	Text = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text")));

	AddChildWidget = NewObject<UUListWidget>(this, List->GetEntryWidgetClass());
	ListAdd = dynamic_cast<UUListWidget*>(AddChildWidget);
	if (List->GetEntryWidgetClass() != NULL)
	{
		AddChildWidget = NewObject<UUListWidget>(this, List->GetEntryWidgetClass());
	}

	UHTTPObject* Object = NewObject<UHTTPObject>();
	if (Object)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, FString::Printf(TEXT("FunctionName : Object")));
		Object->GetJSonCallBack().AddDynamic(this, &UUSideSecondWidget::SaveArrayStart);
	}
	ID = 0;
	DataName =" ";
	DataValue = 0;
	VCID = 0;
	VCName = " ";
	Type = 0;
}


void UUSideSecondWidget::SetListView(int64 idnumber, FString datanamestring, int64 datavalueNumber, int64 vcidNumber, FString vcnameNumber, int64 typeNumber)
{
	DataName = datanamestring;

	ListAdd->SetListView_ListWidget(idnumber, datanamestring, datavalueNumber, vcidNumber, vcnameNumber, typeNumber);

	ItemName.Add(datanamestring);

	if (List->GetEntryWidgetClass() != NULL)
	{
		AddChildWidget = NewObject<UUListWidget>(this, List->GetEntryWidgetClass());

		ListAdd = dynamic_cast<UUListWidget*>(AddChildWidget);

		for (const auto& Items : ItemName)
		{
			/*AddChildWidget = CreateWidget(this, List->GetEntryWidgetClass());
			ListAdd->SetName(FText::FromString(Items));
			List->AddItem(ListAdd);*/
		}
		//ListAdd->SetListName(ItemName);
	}

}

void UUSideSecondWidget::SaveArrayStart(FStructArray Callbackstruct)
{
	/*for (auto Data : Callbackstruct.JsonData)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, FString::Printf(TEXT("FunctionName : Object : %s"),Data));
	}*/
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, FString::Printf(TEXT("FunctionName : SaveArrayStart")));
}

void UUSideSecondWidget::OnGetItemChildren(UObject* pltem, TArray<UObject*>& AChildren)
{
}
