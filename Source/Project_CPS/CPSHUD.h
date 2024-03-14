// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CPSHUD.generated.h"

class UUserWidget;
class UTextBlock;
class UMainWidget;
class UUSideSecondWidget;
class UUListWidget;
/**
 * 
 */

UCLASS()
class PROJECT_CPS_API ACPSHUD : public AHUD
{
	GENERATED_BODY()
	
	ACPSHUD();

private:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UUserWidget> ClassWidget;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> ClassOfWidget;

	UMainWidget* MainWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HTTP", meta = (AllowPrivateAccess = "true"))
	TArray<FString> ItemName;

public:
	UFUNCTION(BlueprintCallable)
	void GetCurrentDay(UTextBlock* Day);

	UFUNCTION(BlueprintCallable)
	UUserWidget* GetClassWidget() const;

	UFUNCTION(BlueprintCallable)
	void ConnectTest(int64 idnumber, FString datanamestring, int64 datavalueNumber, int64 vcidNumber, FString vcnameNumber, int64 typeNumber);

};
