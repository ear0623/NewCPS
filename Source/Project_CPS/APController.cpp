// Fill out your copyright notice in the Description page of Project Settings.


#include "APController.h"
#include "Camera/PlayerCameraManager.h"
#include "PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "CustomActor.h"
#include "HTTPObject.h"
#include "Kismet/GameplayStatics.h"

AAPController::AAPController()
{
	MappingContext = CreateDefaultSubobject<UInputMappingContext>(TEXT("Mappingcontext"));
	Location = { 0.0, 0.0, 0.0 };
	InterSpeed = 0.1f;
}

void AAPController::BeginPlay()
{
	Super::BeginPlay();
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> LocalPlayersubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (LocalPlayersubSystem)
	{
		LocalPlayersubSystem->AddMappingContext(MappingContext, 0);
	}
	MyPlayer = Cast<APlayerPawn>(this->GetPawn());
}

void AAPController::InitSetting()
{
	if (MyPlayer != nullptr)
	{
		GetWorldTimerManager().SetTimer(TimerHandle,this, &AAPController::InitSetting_Camera, 0.01f, true);
	}
}

void AAPController::InitSetting_Camera()
{
	float DeltaTime = FApp::GetDeltaTime();
	//
	FRotator CurrentRotator = MyPlayer->GetSpringArm()->GetRelativeRotation();
	FRotator CurrentRotator_Sub = MyPlayer->GetSubSpringArm()->GetRelativeRotation();
	//
	FRotator ObjectRotator = { 0.0f, 0.0f, 0.0f };
	FRotator ObjectRotator_Sub = { 0.0f, 0.0f, -50.0f };
	//
	FRotator TargetRotator = ObjectRotator;
	FRotator TargetRotator_Sub = ObjectRotator_Sub;
	//
	FRotator InterpRotation = FMath::RInterpTo(CurrentRotator, TargetRotator, DeltaTime, InterSpeed);
	FRotator InterpRotation_Sub = FMath::RInterpTo(CurrentRotator_Sub, TargetRotator_Sub, DeltaTime, InterSpeed);
	//
	MyPlayer->GetSpringArm()->SetRelativeRotation(InterpRotation);
	MyPlayer->GetSubSpringArm()->SetRelativeRotation(InterpRotation_Sub);
	//
	float InterSpeed_Arm = 1.0f;
	float Currentfloat = MyPlayer->GetSpringArm()->TargetArmLength;
	float Targetfloat = 300;
	float Interpfloat = FMath::FInterpTo(Currentfloat, Targetfloat, DeltaTime, InterSpeed_Arm);
	MyPlayer->GetSpringArm()->TargetArmLength = Interpfloat;

	if (FMath::IsNearlyEqual(InterpRotation.Yaw, TargetRotator.Yaw, 1.0f)&& Currentfloat == 300)
	{
		InterSpeed = 1.0;
		MyPlayer->GetSpringArm()->SetRelativeRotation(FRotator(0.0f, 00.0f, 0.0f));
		MyPlayer->GetSubSpringArm()->SetRelativeRotation(FRotator(-50.0f, 0.0f, 0.0f));
		//
		//
		MyPlayer->GetSpringArm()->TargetArmLength = 300.0f;
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

void AAPController::InitSetting_Player_Pos()
{
	InterSpeed = 0.8f;
	float DeltaTime = FApp::GetDeltaTime(); 
	FVector CurrentVector = MyPlayer->GetActorLocation();
	FVector TargetVector = Location;
	FVector InterpVector = FMath::VInterpTo(CurrentVector, TargetVector, DeltaTime, InterSpeed);
	//rotation setting
	FRotator CurrentRotator = MyPlayer->GetActorRotation();
	FRotator TargetRotator = Rotation;
	FRotator InterpRotator = FMath::RInterpTo(CurrentRotator, TargetRotator, DeltaTime, InterSpeed);
	//test
	////loop
	MyPlayer->SetActorLocation(InterpVector);
	//
	if (FMath::IsNearlyEqual(CurrentVector.X, TargetVector.X, 1.0f)&&FMath::IsNearlyEqual(CurrentVector.Y, TargetVector.Y, 1.0f)&&FMath::IsNearlyEqual(CurrentVector.Z, TargetVector.Z, 1.0f))
	{
		InterSpeed = 1.0f;
		//MyPlayer->SetActorLocation(TargetVector);
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
	//rotation
	
	MyPlayer->SetActorRotation(InterpRotator);

	if (FMath::IsNearlyEqual(CurrentRotator.Pitch, TargetRotator.Pitch, 1.0f) && FMath::IsNearlyEqual(CurrentRotator.Yaw, TargetRotator.Yaw, 1.0f) && FMath::IsNearlyEqual(CurrentRotator.Roll, TargetRotator.Roll, 10.0f))
	{
		InterSpeed = 1.0f;
		MyPlayer->SetActorRotation(TargetRotator);
	}
}

void AAPController::InitSetting_SprinArm()
{
	InterSpeed = 0.1f;
	float DeltaTime = FApp::GetDeltaTime(); 
	float Currentfloat = MyPlayer->GetSpringArm()->TargetArmLength;
	float Targetfloat = 300;
	float Interpfloat = FMath::FInterpTo(Currentfloat, Targetfloat, DeltaTime, InterSpeed);
	MyPlayer->GetSpringArm()->TargetArmLength = Interpfloat;

	if (FMath::IsNearlyEqual(Currentfloat, Targetfloat, 1.0f))
	{
		MyPlayer->GetSpringArm()->TargetArmLength = 300.0f;
		GetWorldTimerManager().ClearTimer(TimerHandle_Arm);
	}
}

bool AAPController::GetHit()
{
	FHitResult Hitresult;
	bool ClickValue = this->GetHitResultUnderCursor(ECollisionChannel::ECC_Camera, false, Hitresult);
	if (ClickValue)
	{
		if (Hitresult.GetActor()->ActorHasTag("Switch_Board"))
		{
			FName SaveTag = "Switch_Board";
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("True")));
			Location = Hitresult.GetActor()->GetActorLocation();
			Rotation = Hitresult.GetActor()->GetActorRotation();

			if (Setpos.IsBound())
			{
				Setpos.Broadcast(SaveTag);
			}
			GetWorldTimerManager().SetTimer(TimerHandle, this, &AAPController::InitSetting_Player_Pos, 0.01f, true);
		}
		else if (Hitresult.GetActor()->ActorHasTag("Pipe"))
		{
			FName SaveTag = "Pipe";
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("True")));
			Location = Hitresult.GetActor()->GetActorLocation();
			Rotation = Hitresult.GetActor()->GetActorRotation();
			
			if (Setpos.IsBound())
			{
				Setpos.Broadcast(SaveTag);
			}

			GetWorldTimerManager().SetTimer(TimerHandle, this, &AAPController::InitSetting_Player_Pos, 0.01f, true);
		}
		else if (Hitresult.GetActor()->ActorHasTag("Puller"))
		{
			FName SaveTag = "Puller";
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("True")));
			Location = Hitresult.GetActor()->GetActorLocation();
			Rotation = Hitresult.GetActor()->GetActorRotation();

			if (Setpos.IsBound())
			{
				Setpos.Broadcast(SaveTag);
			}

			GetWorldTimerManager().SetTimer(TimerHandle, this, &AAPController::InitSetting_Player_Pos, 0.01f, true);
		}
		else if (Hitresult.GetActor()->ActorHasTag("Billet_Part_1"))
		{
			FName SaveTag = "Billet_Part_1";
			Location = Hitresult.GetActor()->GetActorLocation();
			Rotation = Hitresult.GetActor()->GetActorRotation();

			if (Setpos.IsBound())
			{
				Setpos.Broadcast(SaveTag);
			}

			GetWorldTimerManager().SetTimer(TimerHandle, this, &AAPController::InitSetting_Player_Pos, 0.01f, true);
		}
		
	}
	return ClickValue;
}

void AAPController::GetClickBTC(UClass* InputClass)
{
	InputClass ;
	return ;
}

void AAPController::SaveTag(FText name)
{
	if (!name.IsEmpty())
	{
		FString ConvertString = name.ToString();
		FName ConvertName = FName(*ConvertString);
		bool SetValue=false;
		TArray<AActor*> FoundActors;
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, ConvertString);
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACustomActor::StaticClass(), FoundActors); 
		for (const auto& Array : FoundActors)
		{
			ACustomActor* TempActor = Cast<ACustomActor>(Array);
			if (TempActor)
			{
				if (ConvertString == TempActor->GetIDName())
				{				
					if (Setpos.IsBound())
					{
						Setpos.Broadcast(ConvertName);
						Location = TempActor->GetTargetMesh()->GetRelativeLocation()+FVector(0.0f,0.0f,20.0f);
						Rotation = TempActor->GetTargetMesh()->GetRelativeRotation();
						GetWorldTimerManager().SetTimer(TimerHandle, this, &AAPController::InitSetting_Player_Pos, 0.01f, true);
						break;
					}
				}
			}
		}
	}
}

void AAPController::SaveId(int64 Id)
{
	if (CheckNumber(Id))
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACustomActor::StaticClass(), FoundActors);
		for (const auto& Array : FoundActors)
		{
			ACustomActor* TempActor = Cast<ACustomActor>(Array);
			if (TempActor)
			{
				if (Id == TempActor->getID())
				{
					if (Setpos_i.IsBound())
					{
						Setpos_i.Broadcast(Id);
						Location = TempActor->GetTargetMesh()->GetRelativeLocation() + FVector(0.0f, 0.0f, 20.0f);
						Rotation = TempActor->GetTargetMesh()->GetRelativeRotation();
						GetWorldTimerManager().SetTimer(TimerHandle, this, &AAPController::InitSetting_Player_Pos, 0.01f, true);
						break;
					}
				}
			}
		}
	}
}

void AAPController::CompareIdAndParentID(int64 ParentId)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACustomActor::StaticClass(), FoundActors);
	for (const auto& Array : FoundActors)
	{
		ACustomActor* TempActor = Cast<ACustomActor>(Array);
		if (TempActor)
		{
			if (ParentId == TempActor->GetParentID())
			{
				if (Setpos_P.IsBound())
				{
					Setpos_P.Broadcast(ParentId);
				}
			}
		}
	}
}

bool AAPController::CheckNumber(int64 Number)
{
	if (Number == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}


