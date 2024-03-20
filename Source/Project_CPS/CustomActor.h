// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomActor.generated.h"

class USkeletalMeshComponent;

UCLASS()
class PROJECT_CPS_API ACustomActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SetLineOnOff(FName name);

	UFUNCTION()
	void SetLineOnOff_Innumber(int64 Id);

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> TargetMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> TargetSkeletalMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> SCene;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data", meta = (AllowPrivateAccess = "true"))
	int64 ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data", meta = (AllowPrivateAccess = "true"))
	TArray<FText> Name_Array;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data", meta = (AllowPrivateAccess = "true"))
	FString IDName;

public:
	int64 getID() {	return ID;}
	TArray<FText> GetNameArray() { return Name_Array; }
	FString GetIDName() { return IDName; }
	TObjectPtr<UStaticMeshComponent> GetTargetMesh() { return TargetMesh; }
	TObjectPtr<USkeletalMeshComponent> GetSkeletalMesh() { return TargetSkeletalMesh; }
};
