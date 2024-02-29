// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AEndlessRunnerScoreSystem.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API AEndlessRunnerScoreSystem : public AActor
{
    GENERATED_BODY()

public:
    AEndlessRunnerScoreSystem();

    // Function to increment the score
    void IncrementScore();

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddToScore(float ScoreToAdd);

    UFUNCTION(BlueprintCallable, Category = "Score")
    float GetScore() const;

protected:
    virtual void BeginPlay() override;

private:
    float CurrentScore;

    // Time interval between score increments (in seconds)
    float TimeBetweenScoreIncrements;

    // Amount to add to the score with each increment
    float ScoreToAddOnIncrement;

    FTimerHandle ScoreTimerHandle;

    float ScoreMultiplier;
};
