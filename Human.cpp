#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include "Human.h"

Human::Human(const unsigned int &player_ID)
{
	if (player_ID < 1 || player_ID > 2)
		throw std::invalid_argument("Invalid player identification, must be 1 or 2");
	else
		player = player_ID;
}

void Human::makeMove(GameBoard &GB)
{
	const unsigned int position = validateMove(GB); // get valid input
	GB.board[stoi(GB.positions[position - 1].substr(0, 1))][stoi(GB.positions[position - 1].substr(1, 1))] = player;
}

const unsigned int Human::validateMove(const GameBoard &GB_ref)
{
	unsigned int input;
	while (true)
	{
		input = 0;
		std::cout << "Where to move? ";
		std::cin >> input;
		if (std::cin.fail() || 
			(input < 1 || input > 9) ||
			(GB_ref.board[stoi(GB_ref.positions[input - 1].substr(0, 1))][stoi(GB_ref.positions[input - 1].substr(1, 1))] != 0))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cout << "Can't proceed with move." << std::endl << std::endl;
		}
		else
		{
			return input;
			break;
		}
	}
}