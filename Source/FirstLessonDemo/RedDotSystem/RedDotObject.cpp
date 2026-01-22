// Fill out your copyright notice in the Description page of Project Settings.


#include "RedDotSystem/RedDotObject.h"

DECLARE_LOG_CATEGORY_EXTERN(RedDotObject, Log, All);
DEFINE_LOG_CATEGORY(RedDotObject);

void URedDotObject::SetParentRedDot(URedDotObject* InParent)
{
	if (!InParent)
	{
		return;
	}

	if (ParentRedDot)
	{
		UE_LOG(RedDotObject, Error, TEXT("SetParentRedDot fail: has parent, %s %s %s"), *RedDotTag.ToString(), *InParent->GetTag().ToString(), *ParentRedDot->GetTag().ToString());
		return;
	}

	if (InParent->GetTag() == RedDotTag)
	{
		UE_LOG(RedDotObject, Error, TEXT("SetParentRedDot fail: parent tag == self tag, %s"), *RedDotTag.ToString());
		return;
	}

	ParentRedDot = InParent;
}

void URedDotObject::AddChildRedDot(URedDotObject* InChild)
{
	if (!InChild)
	{
		return;
	}

	Children.Add(InChild);
}

void URedDotObject::SetRedDotCount(int32 Count)
{
	int32 Diff = Count - RedDotCount;
	RedDotCount = Count;
	OnRedDotCountChange.Broadcast(GetRedDotCount());

	if (ParentRedDot && Diff != 0)
	{
		ParentRedDot->NotifyParent(Diff);
	}
}

void URedDotObject::SetTag(const FGameplayTag& InTag)
{
	RedDotTag = InTag;
}

const FGameplayTag& URedDotObject::GetTag()
{
	return RedDotTag;
}

int32 URedDotObject::GetRedDotCount()
{
	return RedDotCount + ChildrenRedDotCount;
}

void URedDotObject::NotifyParent(int32 Diff)
{
	ChildrenRedDotCount += Diff;
	OnRedDotCountChange.Broadcast(GetRedDotCount());

	if (ParentRedDot && Diff != 0)
	{
		ParentRedDot->NotifyParent(Diff);
	}
}

void URedDotObject::ClearFromTop()
{
	ClearFromTopInternal(0);
}

void URedDotObject::ClearFromTopInternal(int32 index)
{
	int Count = GetRedDotCount();
	RedDotCount = 0;
	ChildrenRedDotCount = 0;
	for (URedDotObject* Child : Children)
	{
		Child->ClearFromTopInternal(index + 1);
	}
	OnRedDotCountChange.Broadcast(GetRedDotCount());

	if (index == 0 && ParentRedDot && Count > 0)
	{
		ParentRedDot->NotifyParent(-Count);
	}
}
