// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstLessonGameMode.h"

#include "Components/Button.h"
#include "FirstLesson/FirstLessonShooterUI.h"
#include "FirstLesson/MainUserWidget.h"
#include "FirstLesson/MailUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void AFirstLessonGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	// create the UI
	if (ShooterUI = CreateWidget<UFirstLessonShooterUI>(UGameplayStatics::GetPlayerController(GetWorld(), 0), ShooterUIClass))
	{
		ShooterUI->AddToViewport(0);
	}
	
	if (MainUI=CreateWidget<UMainUserWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), MainUIClass))
	{
		MainUI->AddToViewport(0);
	}
	
	if (MailUI=CreateWidget<UMailUserWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), MailUIClass))
	{
		MailUI->AddToViewport(0);
		MailUI->SetVisibility(ESlateVisibility::Collapsed);
	}

	
	if (MainUI)
	{
		if (UButton* EmailButton=Cast<UButton>(MainUI->GetWidgetFromName("MailButton")))
		{
			EmailButton->OnClicked.AddDynamic(this,&AFirstLessonGameMode::MailButtonClicked);
		}
	}
	
	if (MailUI)
	{
		if (UButton* CloseButton=Cast<UButton>(MailUI->GetWidgetFromName("CloseButton")))
		{
			CloseButton->OnClicked.AddDynamic(this,&AFirstLessonGameMode::CloseMailButtonClicked);
		}
	}
}

void AFirstLessonGameMode::IncrementTeamScore(uint8 TeamByte)
{
	// retrieve the team score if any
	int32 Score = 0;
	if (int32* FoundScore = TeamScores.Find(TeamByte))
	{
		Score = *FoundScore;
	}

	// increment the score for the given team
	++Score;
	TeamScores.Add(TeamByte, Score);

	// update the UI
	ShooterUI->BP_UpdateScore(TeamByte, Score);
}

void AFirstLessonGameMode::MailButtonClicked()
{
	if (ShooterUI)
	{
		ShooterUI->SetVisibility(ESlateVisibility::Collapsed);
	}
	
	if (MainUI)
	{
		MainUI->SetVisibility(ESlateVisibility::Collapsed);
	}
	
	if (MailUI)
	{
		MailUI->SetVisibility(ESlateVisibility::Visible);
	}
	
	//GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Red,TEXT("ButtonClicked"));

}

void AFirstLessonGameMode::CloseMailButtonClicked()
{
	if (ShooterUI)
	{
		ShooterUI->SetVisibility(ESlateVisibility::Visible);
	}
	
	if (MainUI)
	{
		MainUI->SetVisibility(ESlateVisibility::Visible);
	}
	
	if (MailUI)
	{
		MailUI->SetVisibility(ESlateVisibility::Collapsed);
	}
	
}
