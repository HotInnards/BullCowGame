/*
This is the FBullCowGame class which defines the methods needed for the internal game logic.
The game is a simple guess the word game based on Mastermind.
*/

#pragma once
#include <string>

// change syntax to suit Unreal coding standards
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString) const;
	bool IsGameWon() const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bIsGameWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
