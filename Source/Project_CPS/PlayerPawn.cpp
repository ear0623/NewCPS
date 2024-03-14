// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "APController.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneCaptureComponent2D.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Targetmesh"));
	TargetMesh->SetupAttachment(RootComponent);
	TargetMesh->SetCollisionProfileName(TEXT("NoCollision"));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Springarm"));
	SpringArm->SetupAttachment(TargetMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Sub_SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Sub_Springarm"));
	Sub_SpringArm->SetupAttachment(TargetMesh);

	SceneCapture2D = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Sub_Camera"));
	SceneCapture2D->SetupAttachment(Sub_SpringArm);
	
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	TObjectPtr<UEnhancedInputComponent> Enhanced = Cast< UEnhancedInputComponent>(PlayerInputComponent);
	if(IsValid(Enhanced))
	{
		Enhanced->BindAction(IA_Wheel, ETriggerEvent::Triggered, this, &APlayerPawn::ZoomInOut);
		Enhanced->BindAction(IA_Rotater, ETriggerEvent::Triggered, this, &APlayerPawn::RotatorValue);
		Enhanced->BindAction(IA_MouseAxisX, ETriggerEvent::Triggered, this, &APlayerPawn::RotatorValue);
		Enhanced->BindAction(IA_Click, ETriggerEvent::Started, this, &APlayerPawn::OnClik);
	}

}

void APlayerPawn::ZoomInOut(const FInputActionValue& Value)
{
	float InputValue = Value.Get<float>();
	float Length = GetSpringArm()->TargetArmLength;
	Length += (InputValue*10);
	//UE_LOG(LogTemp, Warning, TEXT("zoominout"));
	GetSpringArm()->TargetArmLength = Length;
}

void APlayerPawn::RotatorValue(const FInputActionValue& Value)
{
	float InputValue = Value.Get<float>();
	if (InputValue > 0.5f && InputValue>0)
	{
		InputValue = 0.5;
	}
	if (InputValue < -0.5f && InputValue < 0)
	{
		InputValue = -0.5;
	}
	FRotator ArmRotatorValue = GetSpringArm()->GetRelativeRotation();
	FRotator ArmRotatorValue_Sub = GetSubSpringArm()->GetRelativeRotation();
	//
	ArmRotatorValue.Yaw += (10 * InputValue);
	ArmRotatorValue_Sub.Yaw += (10 * InputValue);
	//
	GetSpringArm()->SetRelativeRotation(ArmRotatorValue);
	GetSubSpringArm()->SetRelativeRotation(ArmRotatorValue_Sub);
}

void APlayerPawn::OnClik(const FInputActionValue& Value)
{
	bool InputValue = Value.Get<bool>();
	
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("Value : %s"), InputValue ? TEXT("true") : TEXT("false")));

	TObjectPtr<AAPController> AAPcontroller = Cast<AAPController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (AAPcontroller)
	{
		AAPcontroller->GetHit();
	}

}

