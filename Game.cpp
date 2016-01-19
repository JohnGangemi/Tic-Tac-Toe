#include <ctime>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "Game.h"

Game::Game()
{
}

void Game::setGame()
{
	unsigned int input;
	while (true)
	{
		input = 0;
		std::cout << "\nWhat game type?\nHuman vs. Human (1)\nComputer vs. Human (2)\n";
		std::cin >> input;
		if (std::cin.fail() ||
			(input < 1 || input > 2))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cout << "Not a valid option." << std::endl << std::endl;
		}
		else
		{
			if (input == 1)
				noComputer();
			else
				yesComputer();
			break;
		}
	}
}

const void Game::noComputer()
{
	GameBoard game_board;
	Human hum_1(player_1);
	Human hum_2(player_2);

	unsigned int count = 0;

	std::cout << std::endl;

	while (true)
	{
		std::cout << "\nPlayer one...\n";
		hum_1.makeMove(game_board);
		std::cout << std::endl;
		game_board.displayGameBoard();
		count++;
		if (count > 4 && isEnd(game_board, player_1))
			break;

		std::cout << "\nPlayer two...\n";
		hum_2.makeMove(game_board);
		std::cout << std::endl;
		game_board.displayGameBoard();
		count++;
		if (count > 4 && isEnd(game_board, player_2))
			break;
	}
}

const void Game::yesComputer()
{
	GameBoard game_board;
	Human hum(player_1);
	Computer comp(player_2);

	srand(unsigned(time(NULL)));
	unsigned int random_start = rand() % 2;
	unsigned int count = 0;

	std::cout << std::endl;

	if (random_start == 0)
	{
		while (true)
		{
			std::cout << std::endl;
			comp.makeMove(game_board);
			std::cout << std::endl;
			game_board.displayGameBoard();
			count++;
			if (count > 4 && isEnd(game_board, player_2))
				break;

			std::cout << "\nPlayer one...\n";
			hum.makeMove(game_board);
			std::cout << std::endl;
			game_board.displayGameBoard();
			count++;
			if (count > 4 && isEnd(game_board, player_1))
				break;
		}
	}
	else
	{
		while (true)
		{
			std::cout << "\nPlayer one...\n";
			hum.makeMove(game_board);
			std::cout << std::endl;
			game_board.displayGameBoard();
			count++;
			if (count > 4 && isEnd(game_board, player_1))
				break;

			std::cout << std::endl;
			comp.makeMove(game_board);
			std::cout << std::endl;
			game_board.displayGameBoard();
			count++;
			if (count > 4 && isEnd(game_board, player_2))
				break;
		}
	}
}

bool Game::isEnd(GameBoard &GB_ref, const unsigned int &player)
{
	if (GB_ref.getGameState() == 1)
	{
		std::cout << "\nPlayer " << player << " has won the game!" << std::endl;
		return true;
	}
	else if (GB_ref.getGameState() == -1)
	{
		std::cout << "\nGame has ended in a draw" << std::endl;
		return true;
	}
	else
		return false;
}