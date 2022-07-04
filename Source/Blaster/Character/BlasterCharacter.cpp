// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ABlasterCharacter::ABlasterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>( TEXT("CameraBom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void ABlasterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlasterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABlasterCharacter::MoveForward(float Value)
{
	if( Controller != nullptr && Value!= 0.f)
	{
		const FRotator YawRotation( 0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction( FRotationMatrix( YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction,Value);
		
	}
}

void ABlasterCharacter::MoveRight(float Value)
{
}

void ABlasterCharacter::Turn(float Value)
{
}

void ABlasterCharacter::LookUp(float Value)
{
}

void ABlasterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


