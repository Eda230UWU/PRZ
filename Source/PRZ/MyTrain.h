// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyTrain.generated.h"

UCLASS()
class PRZ_API AMyTrain : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyTrain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputMappingContext* UVehicleMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* UControlVehicle;

	/*Vectors for movement*/
	FVector directionVectorR, directionVectorF, ForwardVelocity;
	FRotator moveRotation;
	FVector2D moveVector;

	/*Movement Funcitons*/
	void moveVehicle(const FInputActionValue& Value);
	void changeVelocityFront(FVector Velocity);

	UCharacterMovementComponent* CMC;
	AController* PC;



};
