// Fill out your copyright notice in the Description page of Project Settings.


#include "UListWidget.h"
#include "AStructorActor.h"
#include "UListWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "HTTPObject.h"

void UUListWidget::SetName(FText Listname)
{
	ListName = Listname;
	ItemName_ListWidget.Add(ListName.ToString());
	/*GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, FString::Printf(TEXT("FunctionName = SetName")));
	for (const auto& Items : ItemName_ListWidget)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, Items);
	}*/
}

void UUListWidget::SetListName(TArray<FString> Itemname)
{
	ItemName_ListWidget = Itemname;
}

void UUListWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUListWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UUListWidget* ListWidget = Cast<UUListWidget>(ListItemObject);
	if (ListWidget)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, FString::Printf(TEXT("FunctionName = NativeOnListitemobject")));
		UpdateLsit();
	}
	
}

void UUListWidget::NativeOnItemSelectionChanged(bool bIsSelected)
{

}

void UUListWidget::UpdateListName(FText name)
{
	ListName = name;
}

void UUListWidget::SetListView_ListWidget(int64 idmumber, FString datanamestring, int64 datavalueNumber, int64 vcidNumber, FString vcnameNumber, int64 typeNumber)
{
	ItemName_ListWidget.Add(datanamestring);
	for (const auto& Items : ItemName_ListWidget)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, Items);
	}
}

void UUListWidget::UpdateLsit()
{
	for (const auto& Items : ItemName_ListWidget)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, Items);
		Name->SetText(ListName);
	}
}


void UUListWidget::NativeEventTest_Implementation(int64 number, bool value, const FString& string)
{
}


