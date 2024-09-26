// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputMappingContext.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>

#include "ACDefaultChar.generated.h"


UCLASS()
class PRZ_API AACDefaultChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AACDefaultChar();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputMappingContext* UCharMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* UControlChar;

	/*Vectors for movement*/
	FVector directionVectorR, directionVectorF, ForwardVelocity;
	FRotator moveRotation;
	FVector2D moveVector;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void moveChar(const FInputActionValue& Value);

};
