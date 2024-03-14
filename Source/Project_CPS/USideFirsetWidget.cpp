// Fill out your copyright notice in the Description page of Project Settings.


#include "USideFirsetWidget.h"
#include "Components/TreeView.h"
#include "UListWidget.h"

void UUSideFirsetWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AddChildWidget = NewObject<UUListWidget>(this, TreeViewEquip->GetEntryWidgetClass());
	ListAdd = dynamic_cast<UUListWidget*>(AddChildWidget);

}

void UUSideFirsetWidget::OnGetItemChildren(UObject* pltem, TArray<UObject*>& AChildren)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("FunctionName : OngetItemChildren")));
}

void UUSideFirsetWidget::SetListView(int64 idnumber, FString datanamestring, int64 datavalueNumber, int64 vcidNumber, FString vcnameNumber, int64 typeNumber)
{

	ListAdd->SetListView_ListWidget(idnumber, datanamestring, datavalueNumber, vcidNumber, vcnameNumber, typeNumber);

	ItemName.Add(datanamestring);

	if (TreeViewEquip->GetEntryWidgetClass() != NULL)
	{
		AddChildWidget = NewObject<UUListWidget>(this, TreeViewEquip->GetEntryWidgetClass());

		ListAdd = dynamic_cast<UUListWidget*>(AddChildWidget);

		for (const auto& Items : ItemName)
		{
			/*AddChildWidget = CreateWidget(this, TreeViewEquip->GetEntryWidgetClass());
			ListAdd->SetName(FText::FromString(Items));
			TreeViewEquip->AddItem(ListAdd);*/
		}
	}

}

void UUSideFirsetWidget::SaveArrayStart()
{
}
