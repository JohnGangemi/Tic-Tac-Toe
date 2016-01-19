#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Computer.h"


Computer::Computer(const unsigned int &player_ID)
{
	if (player_ID < 1 || player_ID > 2)
		throw std::invalid_argument("Invalid player identification, must be 1 or 2");
	else
		player = player_ID;

	setDifficulty();
}

void Computer::makeMove(GameBoard &GB)
{
	srand(unsigned(time(NULL)));
	unsigned int random = 0;
	unsigned int random_difficulty = rand() % 10 + 1;

	defensiveMove(GB); // populate vector with possible defensive moves

	// select position based on random number, constant, and vector size
	if (moves.empty() || random_difficulty <= difficulty)
	{
		random = rand() % 9;

		while (GB.board[std::stoi(GB.positions[random].substr(0, 1))][std::stoi(GB.positions[random].substr(1, 1))] != 0)
			random = rand() % 9;

		GB.board[std::stoi(GB.positions[random].substr(0, 1))][std::stoi(GB.positions[random].substr(1, 1))] = player;
		std::cout << "Computer moved to " << random + 1 << std::endl;
	}
	else if (random_difficulty > difficulty)
	{
		random = rand() % moves.size();
	
		GB.board[std::stoi(GB.positions[moves[random] - 1].substr(0, 1))][std::stoi(GB.positions[moves[random] - 1].substr(1, 1))] = player;
		std::cout << "Computer moved to " << moves[random] << std::endl;
	}
}

void Computer::defensiveMove(const GameBoard &GB_ref)
{
	moves.clear(); // clear contents of vector

	// check diagonals
	if ((GB_ref.board[0][0] != player && GB_ref.board[0][0] != 0) && (GB_ref.board[1][1] != player && GB_ref.board[1][1] != 0)
		&& (GB_ref.board[2][2] == 0))
		moves.push_back(9);
	if ((GB_ref.board[0][0] != player && GB_ref.board[0][0] != 0) && (GB_ref.board[2][2] != player && GB_ref.board[2][2] != 0)
		&& (GB_ref.board[1][1] == 0))
		moves.push_back(5);
	if ((GB_ref.board[1][1] != player && GB_ref.board[1][1] != 0) && (GB_ref.board[2][2] != player && GB_ref.board[2][2] != 0)
		&& (GB_ref.board[0][0] == 0))
		moves.push_back(1);

	if ((GB_ref.board[0][2] != player && GB_ref.board[0][2] != 0) && (GB_ref.board[1][1] != player && GB_ref.board[1][1] != 0)
		&& (GB_ref.board[2][0] == 0))
		moves.push_back(7);
	if ((GB_ref.board[0][2] != player && GB_ref.board[0][2] != 0) && (GB_ref.board[2][0] != player && GB_ref.board[2][0] != 0)
		&& (GB_ref.board[1][1] == 0))
		moves.push_back(5);
	if ((GB_ref.board[2][0] != player && GB_ref.board[2][0] != 0) && (GB_ref.board[1][1] != player && GB_ref.board[1][1] != 0)
		&& (GB_ref.board[0][2] == 0))
		moves.push_back(3);

	// check horizontals
	if ((GB_ref.board[0][0] != player && GB_ref.board[0][0] != 0) && (GB_ref.board[0][1] != player && GB_ref.board[0][1] != 0)
		&& (GB_ref.board[0][2] == 0))
		moves.push_back(3);
	if ((GB_ref.board[0][0] != player && GB_ref.board[0][0] != 0) && (GB_ref.board[0][2] != player && GB_ref.board[0][2] != 0)
		&& (GB_ref.board[0][1] == 0))
		moves.push_back(2);
	if ((GB_ref.board[0][1] != player && GB_ref.board[0][1] != 0) && (GB_ref.board[0][2] != player && GB_ref.board[0][2] != 0)
		&& (GB_ref.board[0][0] == 0))
		moves.push_back(1);

	if ((GB_ref.board[1][0] != player && GB_ref.board[1][0] != 0) && (GB_ref.board[1][1] != player && GB_ref.board[1][1] != 0)
		&& (GB_ref.board[1][2] == 0))
		moves.push_back(6);
	if ((GB_ref.board[1][0] != player && GB_ref.board[1][0] != 0) && (GB_ref.board[1][2] != player && GB_ref.board[1][2] != 0)
		&& (GB_ref.board[1][1] == 0))
		moves.push_back(5);
	if ((GB_ref.board[1][1] != player && GB_ref.board[1][1] != 0) && (GB_ref.board[1][2] != player && GB_ref.board[1][2] != 0)
		&& (GB_ref.board[1][0] == 0))
		moves.push_back(4);

	if ((GB_ref.board[2][0] != player && GB_ref.board[2][0] != 0) && (GB_ref.board[2][1] != player && GB_ref.board[2][1] != 0)
		&& (GB_ref.board[2][2] == 0))
		moves.push_back(9);
	if ((GB_ref.board[2][0] != player && GB_ref.board[2][0] != 0) && (GB_ref.board[2][2] != player && GB_ref.board[2][2] != 0)
		&& (GB_ref.board[2][1] == 0))
		moves.push_back(8);
	if ((GB_ref.board[2][1] != player && GB_ref.board[2][1] != 0) && (GB_ref.board[2][2] != player && GB_ref.board[2][2] != 0)
		&& (GB_ref.board[2][0] == 0))
		moves.push_back(7);

	// check verticals
	if ((GB_ref.board[0][0] != player && GB_ref.board[0][0] != 0) && (GB_ref.board[1][0] != player && GB_ref.board[1][0] != 0)
		&& (GB_ref.board[2][0] == 0))
		moves.push_back(7);
	if ((GB_ref.board[0][0] != player && GB_ref.board[0][0] != 0) && (GB_ref.board[2][0] != player && GB_ref.board[2][0] != 0)
		&& (GB_ref.board[1][0] == 0))
		moves.push_back(4);
	if ((GB_ref.board[1][0] != player && GB_ref.board[1][0] != 0) && (GB_ref.board[2][0] != player && GB_ref.board[2][0] != 0)
		&& (GB_ref.board[0][0] == 0))
		moves.push_back(1);

	if ((GB_ref.board[0][1] != player && GB_ref.board[0][1] != 0) && (GB_ref.board[1][1] != player && GB_ref.board[1][1] != 0)
		&& (GB_ref.board[2][1] == 0))
		moves.push_back(8);
	if ((GB_ref.board[0][1] != player && GB_ref.board[0][1] != 0) && (GB_ref.board[2][1] != player && GB_ref.board[2][1] != 0)
		&& (GB_ref.board[1][1] == 0))
		moves.push_back(5);
	if ((GB_ref.board[1][1] != player && GB_ref.board[1][1] != 0) && (GB_ref.board[2][1] != player && GB_ref.board[2][1] != 0)
		&& (GB_ref.board[0][1] == 0))
		moves.push_back(2);

	if ((GB_ref.board[0][2] != player && GB_ref.board[0][2] != 0) && (GB_ref.board[1][2] != player && GB_ref.board[1][2] != 0)
		&& (GB_ref.board[2][2] == 0))
		moves.push_back(9);
	if ((GB_ref.board[0][2] != player && GB_ref.board[0][2] != 0) && (GB_ref.board[2][2] != player && GB_ref.board[2][2] != 0)
		&& (GB_ref.board[1][2] == 0))
		moves.push_back(6);
	if ((GB_ref.board[1][2] != player && GB_ref.board[1][2] != 0) && (GB_ref.board[2][2] != player && GB_ref.board[2][2] != 0)
		&& (GB_ref.board[0][2] == 0))
		moves.push_back(3);
}

void Computer::setDifficulty()
{
	unsigned int input;
	while (true)
	{
		input = 0;
		std::cout << "\nWhat level difficulty?\nEasy (1), Medium (2), Hard (3)\n";
		std::cin >> input;
		if (std::cin.fail() ||
			(input < 1 || input > 3))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		else
		{
			break;
		}
	}

	// set difficulty, the higher the value the easier the game
	switch (input)
	{
	case 1:
		difficulty = 7;
		std::cout << "Computer set to EASY" << std::endl;
		break;
	case 2:
		difficulty = 5;
		std::cout << "Computer set to MEDIUM" << std::endl;
		break;
	case 3:
		difficulty = 3;
		std::cout << "Computer set to HARD" << std::endl;
		break;
	default:
		throw std::invalid_argument("Invalid difficulty");
		break;
	}
}