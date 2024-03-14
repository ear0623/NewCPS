// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TransfromInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTransfromInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECT_CPS_API ITransfromInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void SetListview(int64 Id, FString DataName, int64 DataValue, int64 VCID, FString VCName, int64 Type) = 0;
};
