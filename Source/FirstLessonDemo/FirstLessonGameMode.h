// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FirstLesson/FirstLessonShooterUI.h"
#include "FirstLesson/MainUserWidget.h"
#include "FirstLesson/MailUserWidget.h"
#include "FirstLessonGameMode.generated.h"



class UFirstLessonShooterUI;



/**
 * 
 */
UCLASS(abstract)
class FIRSTLESSONDEMO_API AFirstLessonGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	
	/** Type of UI widget to spawn */
	UPROPERTY(EditAnywhere, Category="Shooter")
	TSubclassOf<UFirstLessonShooterUI> ShooterUIClass;

	/** Pointer to the UI widget */
	TObjectPtr<UFirstLessonShooterUI> ShooterUI;
	
	/** Type of UI widget to spawn */
	UPROPERTY(EditAnywhere, Category="Shooter")
	TSubclassOf<UMainUserWidget> MainUIClass;

	/** Pointer to the UI widget */
	TObjectPtr<UMainUserWidget> MainUI;
	
	/** Type of UI widget to spawn */
	UPROPERTY(EditAnywhere, Category="Shooter")
	TSubclassOf<UMailUserWidget> MailUIClass;

	/** Pointer to the UI widget */
	TObjectPtr<UMailUserWidget> MailUI;

	/** Map of scores by team ID */
	TMap<uint8, int32> TeamScores;

protected:

	/** Gameplay initialization */
	virtual void BeginPlay() override;

public:

	/** Increases the score for the given team */
	void IncrementTeamScore(uint8 TeamByte);

	UFUNCTION()
	void MailButtonClicked();
	
	UFUNCTION()
	void CloseMailButtonClicked();
	
	
};
