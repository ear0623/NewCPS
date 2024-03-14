// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "USideSecondWidget.generated.h"

class UBorder;
class UTextBlock;
class UListView;
class UHTTPObject;
class AHTTPActor;
class UUListWidget;
class UHTTPObject;
struct FStructArray;
class UTreeView;
/**
 * 
 */
UCLASS()
class PROJECT_CPS_API UUSideSecondWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UFUNCTION()
	virtual void NativeConstruct() override;


private:
	UPROPERTY()
	TObjectPtr<UBorder> Background;

	UPROPERTY()
	TObjectPtr<UTextBlock> Text;

	/*UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UListView> List;*/

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UObject> DataObject;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	UUserWidget* AddChildWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> ClassOfWidget;

	UUListWidget* ListAdd;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHTTPObject> HttpObject;

private:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	int64 ID;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	FString DataName;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	int64 DataValue;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	int64 VCID;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	FString VCName;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	int64 Type;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	TArray<FString> ItemName;

	FTimerHandle ArrayHandle;

public:

	UFUNCTION(BlueprintCallable)
	void SetListView(int64 idnumber, FString datanamestring, int64 datavalueNumber, int64 vcidNumber, FString vcnameNumber, int64 typeNumber);


	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UTreeView>  List;

	UFUNCTION(BlueprintCallable)
	TArray<FString> GetItemNameArray() { return ItemName; }

	UUserWidget* GetAddChildWidget() {return AddChildWidget;}

	TObjectPtr<UTreeView> GetList() { return List; }

	UFUNCTION()
	void SaveArrayStart(FStructArray Callbackstruct);

	UFUNCTION()
	void OnGetItemChildren(UObject* pltem, TArray<UObject*>& AChildren);
};
