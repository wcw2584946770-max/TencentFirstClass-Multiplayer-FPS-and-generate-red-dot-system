// Fill out your copyright notice in the Description page of Project Settings.


#include "RedDotSystem/RedDotDeveloperSettings.h"

FName URedDotDeveloperSettings::GetContainerName() const
{
	static const FName ContainerName("Project");
	return ContainerName;
}

FName URedDotDeveloperSettings::GetCategoryName() const
{
	static const FName EditorCategoryName("Project");
	return EditorCategoryName;
}

FName URedDotDeveloperSettings::GetSectionName() const
{
	static const FName TargetSectionName("RedDot System");
	return TargetSectionName;
}

#if WITH_EDITOR
FText URedDotDeveloperSettings::GetSectionText() const
{
	static const FText TargetSectionText = FText::FromString("RedDot System");
	return TargetSectionText;
}

FText URedDotDeveloperSettings::GetSectionDescription() const
{
	static const FText TargetSectionDescription = FText::FromString("Project settings specific");
	return TargetSectionDescription;
}
#endif 
