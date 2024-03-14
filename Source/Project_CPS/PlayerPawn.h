// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
class UStaticMeshComponent;
class USceneCaptureComponent2D;

UCLASS()
class PROJECT_CPS_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component", meta = (AllowPrivateAccess="true"))
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneCaptureComponent2D> SceneCapture2D;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> Sub_SpringArm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Component", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> TargetMesh;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = "Enhaced",meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Wheel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enhaced", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Rotater;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enhaced", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_MouseAxisX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enhaced", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> IA_Click;
public:
	UFUNCTION()
	void ZoomInOut(const FInputActionValue& Value);

	UFUNCTION()
	void RotatorValue(const FInputActionValue& Value);

	UFUNCTION()
	void OnClik(const FInputActionValue& Value);

	TObjectPtr<UCameraComponent> GetCamera() const { return Camera; }
	TObjectPtr<USpringArmComponent> GetSpringArm() const { return SpringArm; }
	TObjectPtr<USpringArmComponent> GetSubSpringArm() const { return Sub_SpringArm; }
	TObjectPtr<UStaticMeshComponent> GetTargetMesh() const { return TargetMesh; }

};
