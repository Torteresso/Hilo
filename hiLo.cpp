#include "hiLo.h"
#include "random.h"
#include <iostream>

namespace HiLo
{
	namespace Parameter
	{
		constexpr int maxValue{ 100 };
		constexpr int minValue{ 1 };
		constexpr int nbGuesses{ 7 };
	}

	int askUserGuess(int tryNb)
	{
		std::cout << "Guess #" << tryNb << " : ";

		int guess{};
		
		std::cin >> guess;

		return guess;

	}

	bool evaluateGuess(int userGuess, int target)
	{
		if (userGuess > target)
		{
			std::cout << "Your guess is too high." << '\n';
			return false;
		}
		else if (userGuess < target)
		{
			std::cout << "Your guess is too low" << '\n';
			return false;
		}
		else
		{
			std::cout << "Correct ! You win !" << '\n';
			return true;
		}
	}

	bool isPlayingAgain()
	{
		char userResponse{};
	
		do
		{
			std::cout << "Would you like to play again (y/n)? ";

			std::cin >> userResponse;

		} while (userResponse != 'y' && userResponse != 'n');

		return (userResponse == 'y');
	}

	void userIsGuessing(int targetNumber)
	{
		int currentTryNb{ 0 };

		do
		{
			++currentTryNb;


			if (evaluateGuess(askUserGuess(currentTryNb), targetNumber))
				break;

			if (currentTryNb == Parameter::nbGuesses)
			{
				std::cout << "Sorry, you lose. The correct number was " << targetNumber << ".\n";
			}
		} while (currentTryNb < Parameter::nbGuesses);
	}

	void play()
	{
		bool userWantsToPlay{true};
		do
		{
			const int targetNumber{ Random::get(Parameter::minValue, Parameter::maxValue) };

			std::cout << "Lets play a game. I'm thinking of a number between " << Parameter::minValue <<
				" and " << Parameter::maxValue << ". You have " << Parameter::nbGuesses << " tries to guess what."
				<< '\n';

			userIsGuessing(targetNumber);

			userWantsToPlay = isPlayingAgain();

		} while (userWantsToPlay);

		std::cout << "Thanks for playing.";
	}
}