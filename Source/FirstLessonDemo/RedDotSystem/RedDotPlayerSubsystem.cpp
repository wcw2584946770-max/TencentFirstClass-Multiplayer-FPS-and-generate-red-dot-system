// Fill out your copyright notice in the Description page of Project Settings.


#include "RedDotSystem/RedDotPlayerSubsystem.h"
#include "RedDotDeveloperSettings.h"

void URedDotPlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	const URedDotDeveloperSettings* CurrentDeveloperSettings = GetDefault<URedDotDeveloperSettings>();
	if (!CurrentDeveloperSettings->RedDotAsset.IsNull())
	{
		URedDotDataAsset* RedDotAsset = CurrentDeveloperSettings->RedDotAsset.LoadSynchronous();
		GenerateRedDots(RedDotAsset);
	}
}

void URedDotPlayerSubsystem::SetRedDotCount(FGameplayTag RedDotTag, int32 Count)
{
	if (!RedDotTag.IsValid())
	{
		return;
	}

	URedDotObject* Object = RedDotMap.FindRef(RedDotTag);
	if (Object)
	{
		Object->SetRedDotCount(Count);
	}
}

void URedDotPlayerSubsystem::BindOnRedDotChange(FGameplayTag RedDotTag, FRedDotCountCallBack Delegate)
{
	if (!RedDotTag.IsValid())
	{
		return;
	}

	URedDotObject* Object = RedDotMap.FindRef(RedDotTag);
	if (Object)
	{
		Object->OnRedDotCountChange.Add(Delegate);
		Delegate.ExecuteIfBound(Object->GetRedDotCount());
	}
}

void URedDotPlayerSubsystem::ClearFromTop(FGameplayTag RedDotTag)
{
	if (!RedDotTag.IsValid())
	{
		return;
	}

	URedDotObject* Object = RedDotMap.FindRef(RedDotTag);
	if (Object)
	{
		Object->ClearFromTop();
	}
}

void URedDotPlayerSubsystem::GenerateRedDots(URedDotDataAsset* RedDotAsset)
{
	if (!RedDotAsset)
	{
		return;
	}

	TMap<FGameplayTag, FRedDotInfo>& RedDotInfoMap = RedDotAsset->RedDotMap;
	for (auto& Pair : RedDotInfoMap)
	{
		FRedDotInfo& Info = Pair.Value;
		const FGameplayTag& RedDotTag = Pair.Key;
		if (!RedDotTag.IsValid())
		{
			continue;
		}

		URedDotObject* Object = RedDotMap.FindRef(RedDotTag);
		if (!Object)
		{
			Object = NewObject<URedDotObject>(this);
			Object->SetTag(RedDotTag);
			RedDotMap.Add(RedDotTag, Object);
		}

		if (Info.ParentTag.IsValid())
		{
			URedDotObject* ParentNode = RedDotMap.FindRef(Info.ParentTag);
			if (!ParentNode)
			{
				ParentNode = NewObject<URedDotObject>(this);
				ParentNode->SetTag(Info.ParentTag);
				RedDotMap.Add(Info.ParentTag, ParentNode);
			}
			ParentNode->AddChildRedDot(Object);
			Object->SetParentRedDot(ParentNode);
		}
	}
}


