// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstLesson/MailUserWidget.h"

#include "Components/Button.h"
#include "Engine/AssetManager.h"

#include "RedDotSystem/RedDotPlayerSubsystem.h"

void UMailUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	OnMailButtonClicked1.BindUFunction(this,FName("OnRedDotUpdate1"));
	OnMailButtonClicked2.BindUFunction(this,FName("OnRedDotUpdate2"));
	OnMailButtonClicked3.BindUFunction(this,FName("OnRedDotUpdate3"));
	auto RedDotSystem= GetOwningLocalPlayer()->GetSubsystem<URedDotPlayerSubsystem>();
	if (RedDotSystem)
	{
		FGameplayTag GamePlayTag1= FGameplayTag::RequestGameplayTag(FName("RedDot.Mail1"));
		FGameplayTag GamePlayTag2= FGameplayTag::RequestGameplayTag(FName("RedDot.Mail2"));
		FGameplayTag GamePlayTag3= FGameplayTag::RequestGameplayTag(FName("RedDot.Mail3"));
		RedDotSystem->BindOnRedDotChange(GamePlayTag1,OnMailButtonClicked1);
		RedDotSystem->BindOnRedDotChange(GamePlayTag2,OnMailButtonClicked2);
		RedDotSystem->BindOnRedDotChange(GamePlayTag3,OnMailButtonClicked3);
	}
	
	if (SetButton1)
	{
		SetButton1->OnClicked.AddDynamic(this, &UMailUserWidget::SetButtonClicked1);
	}
	
	if (SetButton2)
	{
		SetButton2->OnClicked.AddDynamic(this, &UMailUserWidget::SetButtonClicked2);
	}
	
	if (SetButton3)
	{
		SetButton3->OnClicked.AddDynamic(this, &UMailUserWidget::SetButtonClicked3);
	}
	
	if (ClearButton1)
	{
		ClearButton1->OnClicked.AddDynamic(this, &UMailUserWidget::ClearButtonClicked1);
	}
	
	if (ClearButton2)
	{
		ClearButton2->OnClicked.AddDynamic(this, &UMailUserWidget::ClearButtonClicked2);
	}
	
	if (ClearButton3)
	{
		ClearButton3->OnClicked.AddDynamic(this, &UMailUserWidget::ClearButtonClicked3);
	}
}

void UMailUserWidget::SetButtonClicked1()
{
	auto RedDotSystem= GetOwningLocalPlayer()->GetSubsystem<URedDotPlayerSubsystem>();
	if (RedDotSystem)
	{
		FGameplayTag GamePlayTag= FGameplayTag::RequestGameplayTag(FName("RedDot.Mail1"));
		RedDotSystem->SetRedDotCount( GamePlayTag,1);
	}
	

	
}

void UMailUserWidget::SetButtonClicked2()
{
	auto RedDotSystem= GetOwningLocalPlayer()->GetSubsystem<URedDotPlayerSubsystem>();
	if (RedDotSystem)
	{
		FGameplayTag GamePlayTag= FGameplayTag::RequestGameplayTag(FName("RedDot.Mail2"));
		RedDotSystem->SetRedDotCount( GamePlayTag,3);
	}
	
	
}

void UMailUserWidget::SetButtonClicked3()
{
	auto RedDotSystem= GetOwningLocalPlayer()->GetSubsystem<URedDotPlayerSubsystem>();
	if (RedDotSystem)
	{
		FGameplayTag GamePlayTag= FGameplayTag::RequestGameplayTag(FName("RedDot.Mail3"));
		RedDotSystem->SetRedDotCount( GamePlayTag,10);
	}
	
	
}

void UMailUserWidget::ClearButtonClicked1()
{
	auto RedDotSystem= GetOwningLocalPlayer()->GetSubsystem<URedDotPlayerSubsystem>();
	if (RedDotSystem)
	{
		FGameplayTag GamePlayTag= FGameplayTag::RequestGameplayTag(FName("RedDot.Mail1"));
		RedDotSystem->SetRedDotCount( GamePlayTag,0);
	}
	
	
}

void UMailUserWidget::ClearButtonClicked2()
{
	auto RedDotSystem= GetOwningLocalPlayer()->GetSubsystem<URedDotPlayerSubsystem>();
	if (RedDotSystem)
	{
		FGameplayTag GamePlayTag= FGameplayTag::RequestGameplayTag(FName("RedDot.Mail2"));
		RedDotSystem->SetRedDotCount( GamePlayTag,0);
	}
	
	
}

void UMailUserWidget::ClearButtonClicked3()
{
	auto RedDotSystem= GetOwningLocalPlayer()->GetSubsystem<URedDotPlayerSubsystem>();
	if (RedDotSystem)
	{
		FGameplayTag GamePlayTag= FGameplayTag::RequestGameplayTag(FName("RedDot.Mail3"));
		RedDotSystem->SetRedDotCount( GamePlayTag,0);
	}
	
	
}

void UMailUserWidget::ClearFromTop()
{
	auto RedDotSystem= GetOwningLocalPlayer()->GetSubsystem<URedDotPlayerSubsystem>();
	if (RedDotSystem)
	{
		FGameplayTag GamePlayTag= FGameplayTag::RequestGameplayTag(FName("RedDot"));
		RedDotSystem->ClearFromTop(GamePlayTag);
	}
	
	
}

void UMailUserWidget::OnRedDotUpdate1(int Count)
{
	if (Count > 0)
	{
		RedDot1->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		RedDot1->SetVisibility(ESlateVisibility::Collapsed);
	}
	
}

void UMailUserWidget::OnRedDotUpdate2(int Count)
{
	if (Count > 0)
	{
		RedDot2->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		RedDot2->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UMailUserWidget::OnRedDotUpdate3(int Count)
{
	if (Count > 0)
	{
		RedDot3->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		RedDot3->SetVisibility(ESlateVisibility::Collapsed);
	}
}
