// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RedDotSystem/RedDotPlayerSubsystem.h" 
#include "Components/Image.h"
#include "MailUserWidget.generated.h"

// DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRedDotSystemGenerateTree);

/**
 * 
 */
UCLASS()
class FIRSTLESSONDEMO_API UMailUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY()
	URedDotPlayerSubsystem::FRedDotCountCallBack OnMailButtonClicked1;
	
	UPROPERTY()
	URedDotPlayerSubsystem::FRedDotCountCallBack OnMailButtonClicked2;
	
	UPROPERTY()
	URedDotPlayerSubsystem::FRedDotCountCallBack OnMailButtonClicked3;
	
protected:
	virtual void NativeConstruct() override; 
	
	UFUNCTION()
	void SetButtonClicked1();
	UFUNCTION()
	void SetButtonClicked2();
	UFUNCTION()
	void SetButtonClicked3();
	UFUNCTION()
	void ClearButtonClicked1();
	UFUNCTION()
	void ClearButtonClicked2();
	UFUNCTION()
	void ClearButtonClicked3();
	
	UFUNCTION()
	void  ClearFromTop();
	
	UFUNCTION()
	void  OnRedDotUpdate1(int Count);
	
	UFUNCTION()
	void  OnRedDotUpdate2(int Count);
	
	UFUNCTION()
	void  OnRedDotUpdate3(int Count);

	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UButton* SetButton1;

	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UButton* SetButton2;
	
	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UButton* SetButton3;
	
	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UButton* ClearButton1;
	
	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UButton* ClearButton2;
	
	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UButton* ClearButton3;
	
	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UButton* ClearFromTopButton;
	
	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UImage* RedDot1;
	
	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UImage* RedDot2;
	
	UPROPERTY(BlueprintReadOnly, Category = "Mail Widget", meta = (BindWidgetOptional))
	class UImage* RedDot3;
};
