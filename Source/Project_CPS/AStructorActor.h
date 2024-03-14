// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AStructorActor.generated.h"

USTRUCT(BlueprintType)
struct FSampleStruct : public FTableRowBase
{
	GENERATED_BODY()


	FSampleStruct():rowname(1),SpellName(" "), Description(" "), Level(1), isEndItem(0) {}
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int64 rowname;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString SpellName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int64 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int64 isEndItem;

public:
	int64 Getrowname() { return rowname; }
	void Setrowname(int64 row) { rowname = row; }
	//
	int64 GetLevel() { return Level; }
	void SetLevel(int64 level) { Level = level; }
	//
	int64 GetisEndItem() { return isEndItem; }
	void SetisEndItem(int64 isendItem) { isEndItem = isendItem; }
	//
	FString GetSpellName() { return SpellName; }
	void SetSpellName(FString name) { SpellName = name; }
	//
	FString GetDescription() { return Description; }
	void SetDescription(FString Des) { Description = Des; }
};

UCLASS()
class PROJECT_CPS_API AAStructorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAStructorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	
	FSampleStruct GetDataTable() { return DataTable; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FSampleStruct DataTable;

public:

	UFUNCTION(BlueprintCallable)
	void SetData();
	
	
};
