// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FirstLessonShooterUI.generated.h"

/**
 * 
 */
UCLASS(abstract)
class FIRSTLESSONDEMO_API UFirstLessonShooterUI : public UUserWidget
{
	GENERATED_BODY()
public:	
	/** Allows Blueprint to update score sub-widgets */
	UFUNCTION(BlueprintImplementableEvent, Category="FirstLessonShooter", meta = (DisplayName = "Update Score"))
	void BP_UpdateScore(uint8 TeamByte, int32 Score);
};
