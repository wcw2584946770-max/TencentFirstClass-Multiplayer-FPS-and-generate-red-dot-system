// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "RedDotObject.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTLESSONDEMO_API URedDotObject : public UObject
{
	GENERATED_BODY()
	
public:
	void SetParentRedDot(URedDotObject* InParent);

	void AddChildRedDot(URedDotObject* InChild);

	void SetRedDotCount(int32 Count);

	void SetTag(const FGameplayTag& InTag);

	const FGameplayTag& GetTag();

	int32 GetRedDotCount();

	void NotifyParent(int32 Diff);

	void ClearFromTop();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRedDotCountChange, int32, Count);
	FOnRedDotCountChange OnRedDotCountChange;

private:
	void ClearFromTopInternal(int32 index);
protected:

	UPROPERTY()
	URedDotObject* ParentRedDot;

	UPROPERTY()
	TSet<URedDotObject*> Children;

	int32 RedDotCount;

	int32 ChildrenRedDotCount;

	FGameplayTag RedDotTag;
};

