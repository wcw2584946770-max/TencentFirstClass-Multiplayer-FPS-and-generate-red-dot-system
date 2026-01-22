// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "RedDotSystem/RedDotDataAsset.h"
#include "RedDotSystem/RedDotObject.h"
#include "GameplayTagContainer.h"
#include "RedDotPlayerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTLESSONDEMO_API URedDotPlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "RedDotPlayerSubsystem")
	void SetRedDotCount(FGameplayTag RedDotTag, int32 Count);

	DECLARE_DYNAMIC_DELEGATE_OneParam(FRedDotCountCallBack, int32, Count);

	UFUNCTION(BlueprintCallable, Category = "RedDotPlayerSubsystem")
	void BindOnRedDotChange(FGameplayTag RedDotTag, UPARAM(DisplayName = "Event") FRedDotCountCallBack Delegate);

	UFUNCTION(BlueprintCallable, Category = "RedDotPlayerSubsystem")
	void ClearFromTop(FGameplayTag RedDotTag);

	UFUNCTION(BlueprintCallable, Category = "RedDotPlayerSubsystem")
	void GenerateRedDots(URedDotDataAsset* RedDotAsset);
private:

	UPROPERTY()
	TMap<FGameplayTag, URedDotObject*> RedDotMap;
};

