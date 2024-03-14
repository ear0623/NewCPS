// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "USideFirsetWidget.generated.h"

class UTreeView;
class UUListWidget;
/**
 * 
 */
UCLASS()
class PROJECT_CPS_API UUSideFirsetWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UFUNCTION()
	virtual void NativeConstruct() override;

private:
	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UTreeView> TreeViewEquip;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	UUserWidget* AddChildWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	TArray<FString> ItemName;

	UUListWidget* ListAdd;

public:
	UFUNCTION()
	void OnGetItemChildren(UObject* pltem, TArray<UObject*>& AChildren);

	UFUNCTION(BlueprintCallable)
	void SetListView(int64 idnumber, FString datanamestring, int64 datavalueNumber, int64 vcidNumber, FString vcnameNumber, int64 typeNumber);

	void SaveArrayStart();
};
