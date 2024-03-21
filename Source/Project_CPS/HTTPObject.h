// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "HTTPObject.generated.h"

USTRUCT(BlueprintType)
struct FJsonThirdChildStruct
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 node_id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString node_name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 parent_id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString type = " ";

};
USTRUCT(BlueprintType)
struct FJsonSecondChildStruct
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 node_id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString node_name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 parent_id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString type = " ";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TArray<FJsonThirdChildStruct> JsonThirdChildData;
};

USTRUCT(BlueprintType)
struct FJsonFirstChildStruct
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 node_id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString node_name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 parent_id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString type = " ";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TArray<FJsonSecondChildStruct> JsonSecondChildData;
};

USTRUCT(BlueprintType)
struct FJsonStruct
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 node_id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString node_name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 parent_id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString type = " ";



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Total = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TArray<FJsonFirstChildStruct> JsonFirstChildData;

};

USTRUCT(BlueprintType)
struct FJsonType01Struct
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 itemId = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString dataName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 dataValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 vcId = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString vcName = " ";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 type = 0;

public:
	int64 GetItemId() { return itemId; }
	void SetItemId(int64 itemID) { itemId = itemID; }
	//
	FString GetItemName() { return dataName; }
	void SetItemName(FString ItemName) { dataName = ItemName; }
	//
	int64 GetDataValue() { return dataValue; }
	void SETDataValue(int64 DataValue) { dataValue = DataValue; }
	//
	int64 GetVcID() { return vcId; }
	void SETVcID(int64 vcID) { vcId = vcID; }
	//
	FString GetVcName() { return vcName; }
	void SetVcName(FString vcname) { vcName = vcname; }
	//
	int64 GetType() { return type; }
	void SETType(int64 Type) { type = Type; }
};

USTRUCT(BlueprintType)
struct FStructArray
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TArray<FJsonStruct> JsonData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TArray<FJsonType01Struct> JsonData_Type01;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHttpConnectStartDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_JSonCallBack,FStructArray,Callbackstruct);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_JSonCallBack_Type01, FStructArray, Callbackstruct);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHttpConnectProcessDelegate, int32, RecvSize, int32, TotalSize, float, Percent); 
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHttpConnectFinishedDelegate, bool, bIsSuccess, FString, ContentPath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FDeleGetHTTPData, int64, Id, FString, DataName, int64, DataValue, int64, VCID, FString, VCName, int64, Type);


class UUSideSecondWidget;
class ACPSHUD;
class FJsonObject;
class FJsonValue;
struct FStructArray;
class FJsonObject;
struct FJsonFirstStruct;
struct FJsonType01Struct;


USTRUCT(BlueprintType)
struct FSaveIndexStruct : public FTableRowBase 
{
	GENERATED_BODY()


	FSaveIndexStruct() :ItemId(1), ItemName(" "), DataValue(1), VcID(1), VcName(" "), Type(1),LoopCount(0) {}
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int64 ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int64 DataValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int64 VcID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString VcName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int64 Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int64 LoopCount;

	TArray<int64> testArray;
public:
	int64 GetItemId() { return ItemId; }
	void SetItemId(int64 itemId) { ItemId = itemId; }
	//
	FString GetItemName() { return ItemName; }
	void SetItemName(FString itemName) { ItemName = itemName; }
	//
	int64 GetDataValue() { return DataValue; }
	void SETDataValue(int64 dataValue) { DataValue = dataValue; }
	//
	int64 GetVcID() { return VcID; }
	void SETVcID(int64 vcID) { VcID = vcID; }
	//
	FString GetVcName() { return VcName; }
	void SetVcName(FString vcName) { VcName = vcName; }
	//
	int64 GetType() { return Type; }
	void SETType(int64 type) { Type = type; }

	int64 GetLoopcount() { return LoopCount; }
	void SetLoopcount(int64 loopcount) { LoopCount = loopcount; }
};

UENUM(BlueprintType)
enum class SettingAPI : uint8
{
	None = 0,
	Type01 = 10,
	Type02 = 50,
};
/**
 * 
 */
UCLASS(BlueprintType)
class PROJECT_CPS_API UHTTPObject : public UObject
{
	GENERATED_BODY()
	
	UHTTPObject(const class FObjectInitializer& ObjectInitializer);

public:
	UHTTPObject();

	UFUNCTION(BlueprintCallable,Category = "HTTP", DisplayName = "HttpConnect")
	void ExcuteHttp(FString SourceURL, FString Path_1, FString Path_2, FString Name, SettingAPI APIenum);

	UPROPERTY(BlueprintAssignable)
	FHttpConnectStartDelegate OnHttpConnectStartCallback;

	UPROPERTY(BlueprintAssignable)
	FHttpConnectProcessDelegate OnHttpConnectProcessCallback;

	UPROPERTY(BlueprintAssignable)
	FHttpConnectFinishedDelegate OnHttpConnectFinishedCallback;

	UPROPERTY(BlueprintAssignable)
	FDele_JSonCallBack JSonCallBack;

	UPROPERTY(BlueprintAssignable)
	FDele_JSonCallBack_Type01 JSonCallBack_Type01;

	UFUNCTION(BlueprintCallable)
	void MyHttpCall();

	bool CheckNull(int64 number);

private:
	FHttpModule* HttpModule;

	void HttpRequestProgressDelegate(FHttpRequestPtr RequestPtr, int32 SendBytes, int32 RevBytes);

	void HttpRequsetFinishedDelegate(FHttpRequestPtr Request, FHttpResponsePtr Respones, bool bWasSuccessful);

	
private:
	UPROPERTY()
	FString SourceURL;

	UPROPERTY()
	FString Path;

	UPROPERTY()
	FString Path2;

	UPROPERTY()
	FString Path3;

	UPROPERTY()
	FString Path4;

	UPROPERTY()
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = " Struct", meta = (AllowPrivateAccess = "true"))
	FDeleGetHTTPData HttpData;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category =" Struct", meta = (AllowPrivateAccess = "true"))
	FSaveIndexStruct SaveObject;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = " Struct", meta = (AllowPrivateAccess = "true"))
	FStructArray StructArray_Json;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widget", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UUSideSecondWidget> ListWidgetPtr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Widget", meta = (AllowPrivateAccess = "true"))
	ACPSHUD* MyHud;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ENum", meta = (AllowPrivateAccess = "true"))
	SettingAPI APIENum;

	int64 Count = 0;
public:

	FDeleGetHTTPData GetHttpData() { return HttpData;}

	FSaveIndexStruct GetSaveObject() { return SaveObject; }

	FStructArray GetStructArray() { return StructArray_Json; }

	UFUNCTION()
	FDele_JSonCallBack GetJSonCallBack() { return JSonCallBack; }
	//

	void Tempsave();


	void ParseParent(const TSharedPtr<FJsonObject>& JsonObject, FStructArray& CallbackStruct);

	void ParseZeroChild(const TSharedPtr<FJsonObject>& JsonObject, FJsonStruct& ZeroChild);

	void ParseFirstChild(const TSharedPtr<FJsonObject>& JsonObject, FJsonFirstChildStruct& FirstChild);

	void ParseSecondChild(const TSharedPtr<FJsonObject>& JsonObject, FJsonSecondChildStruct& SecondChild);
	
	//

	void ParseParent_Type01(const TSharedPtr<FJsonObject>& JsonObject, FStructArray& CallbackStruct);
};
