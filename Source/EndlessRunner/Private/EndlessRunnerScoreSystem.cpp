// Fill out your copyright notice in the Description page of Project Settings.


#include "AEndlessRunnerScoreSystem.h"

AEndlessRunnerScoreSystem::AEndlessRunnerScoreSystem()
{
    PrimaryActorTick.bCanEverTick = false;

    // Initialize score-related variables
    CurrentScore = 0.0f;
    TimeBetweenScoreIncrements = 0.3f; // Adjust this interval as needed
    ScoreToAddOnIncrement = 0.5f; // Adjust the score increment amount as needed
    ScoreMultiplier = 1.0f;
}

void AEndlessRunnerScoreSystem::BeginPlay()
{
    Super::BeginPlay();

    // Set up the timer to increment the score
    GetWorldTimerManager().SetTimer(ScoreTimerHandle, this, &AEndlessRunnerScoreSystem::IncrementScore, TimeBetweenScoreIncrements, true);
}

void AEndlessRunnerScoreSystem::IncrementScore()
{
    // Increment the score at regular intervals
    ScoreMultiplier += 0.1f;
    AddToScore(ScoreToAddOnIncrement * ScoreMultiplier);
}

void AEndlessRunnerScoreSystem::AddToScore(float ScoreToAdd)
{
    CurrentScore += ScoreToAdd;
}

float AEndlessRunnerScoreSystem::GetScore() const
{
    return CurrentScore;
}

