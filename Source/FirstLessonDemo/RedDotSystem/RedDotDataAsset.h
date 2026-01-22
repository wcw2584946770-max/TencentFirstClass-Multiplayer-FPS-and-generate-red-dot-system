// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "RedDotDataAsset.generated.h"

USTRUCT()
struct FRedDotInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "GenericPanelInfo")
	FGameplayTag ParentTag;
};


/**
 * 
 */
UCLASS()
class FIRSTLESSONDEMO_API URedDotDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "RedDotDataAsset")
	TMap<FGameplayTag, FRedDotInfo> RedDotMap;
};

