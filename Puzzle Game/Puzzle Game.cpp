// Puzzle Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Board.h"
#include "Direction.h"
#include "UserInput.h"
#include <iostream>
#include <chrono>
#include "Timer.h"


bool restartGame(const Board& board, const auto& timer)
{
	std::cout << "You win!" << std::endl;

	std::cout << "=== Match stats ===" << std::endl;
	std::cout << "Moves: " << board.totalMoves << " Time spent: " << timer << std::endl;

	std::cout << std::endl;

	std::cout << "Want to play again? [y/n]: " << std::endl;

	while (true)
	{
		char ch{ UserInput::getCommand() };

		if (ch == 'y')
			return false;
		else if (ch == 'n')
			return true;
	}
}

int main()
{
	bool quit{ false };

	while (!quit)
	{
		Board board{};
		board.randomize(); // Randomize tiles positions on board

		auto start{ Timer::start() };

		while (board.winCondtion() == false)
		{
			std::cout << board; // Update console with a new board

			char ch{ UserInput::getCommand() }; // Get input from user

			board.moveTile(Direction{ ch }); // Move tile 
			++board.totalMoves;

			if (ch == 'q')
				return 0;
		}
		auto stop{ Timer::stop() };

		quit = restartGame(board, Timer::duration(stop, start));


	}

	return 0;
}
