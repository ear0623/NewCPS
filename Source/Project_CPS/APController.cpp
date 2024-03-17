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

	//UHTTPObject* UhttObject = NewObject<UHTTPObject>();
	//if(uhttp)

	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Emerald, FString::Printf(TEXT("Here is APCController BeginPlay")));
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
	FRotator ObjectRotator = { 0.0f, 10.0f, 0.0f };
	FRotator ObjectRotator_Sub = { -50.0f, 10.0f, 0.0f };
	//
	FRotator TargetRotator = ObjectRotator;
	FRotator TargetRotator_Sub = ObjectRotator_Sub;
	//
	FRotator InterpRotation = FMath::RInterpTo(CurrentRotator, TargetRotator, DeltaTime, InterSpeed);
	FRotator InterpRotation_Sub = FMath::RInterpTo(CurrentRotator_Sub, TargetRotator_Sub, DeltaTime, InterSpeed);
	//
	MyPlayer->GetSpringArm()->SetWorldRotation(InterpRotation);
	MyPlayer->GetSubSpringArm()->SetWorldRotation(InterpRotation_Sub);
	//
	float InterSpeed_Arm = 1.0f;
	float Currentfloat = MyPlayer->GetSpringArm()->TargetArmLength;
	float Targetfloat = 300;
	float Interpfloat = FMath::FInterpTo(Currentfloat, Targetfloat, DeltaTime, InterSpeed_Arm);
	MyPlayer->GetSpringArm()->TargetArmLength = Interpfloat;

	if (FMath::IsNearlyEqual(InterpRotation.Yaw, TargetRotator.Yaw, 1.0f)&& Currentfloat == 300)
	{
		MyPlayer->GetSpringArm()->SetWorldRotation(FRotator(0.0f, 10.0f, 0.0f));
		MyPlayer->GetSubSpringArm()->SetWorldRotation(FRotator(0.0f, 10.0f, 0.0f));
		//
		MyPlayer->GetSpringArm()->TargetArmLength = 300.0f;
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

void AAPController::InitSetting_Player_Pos()
{
	InterSpeed = 0.1f;
	float DeltaTime = FApp::GetDeltaTime(); 
	FVector CurrentVector = MyPlayer->GetActorLocation();
	FVector TargetVector = Location;
	FVector InterpVector = FMath::VInterpTo(CurrentVector, TargetVector, DeltaTime, InterSpeed);
	MyPlayer->SetActorLocation(InterpVector);
	//
	InterSpeed += 0.1f;
	//
	if (FMath::IsNearlyEqual(CurrentVector.X, TargetVector.X, 1.0f)&&FMath::IsNearlyEqual(CurrentVector.Y, TargetVector.Y, 1.0f)&&FMath::IsNearlyEqual(CurrentVector.Z, TargetVector.Z, 100.0f))
	{
		MyPlayer->SetActorLocation(TargetVector);
		GetWorldTimerManager().ClearTimer(TimerHandle);
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
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, Hitresult.GetActor()->GetClass()->GetName());
	if (ClickValue)
	{
		if (Hitresult.GetActor()->ActorHasTag("Switch_Board"))
		{
			FName SaveTag = "Switch_Board";
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("True")));
			Location = Hitresult.GetActor()->GetActorLocation();
			FRotator Rotation = Hitresult.GetActor()->GetActorRotation();

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
			FRotator Rotation = Hitresult.GetActor()->GetActorRotation();
			
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
			FRotator Rotation = Hitresult.GetActor()->GetActorRotation();

			if (Setpos.IsBound())
			{
				Setpos.Broadcast(SaveTag);
			}

			GetWorldTimerManager().SetTimer(TimerHandle, this, &AAPController::InitSetting_Player_Pos, 0.01f, true);
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("ClickValuFail")));
	return ClickValue;
}

void AAPController::SaveTag()
{

}


