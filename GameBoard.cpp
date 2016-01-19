#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "GameBoard.h"

const std::string GameBoard::positions[positions_size] =
{"00", "01", "02", "10", "11", "12", "20", "21", "22"};

GameBoard::GameBoard()
{
	for (unsigned int i = 0; i < board_size; i++)
	{
		for (unsigned int j = 0; j < board_size; j++)
			board[i][j] = 0;
	}
}

const int GameBoard::getGameState()
{
	if (isWon())
		return 1;
	else if (isDraw())
		return -1;
	else 
		return 0;
}

const void GameBoard::displayGameBoard()
{
	for (unsigned int i = 0; i < board_size; i++)
	{
		for (unsigned int j = 0; j < board_size; j++)
		{
			if (board[i][j] == 0)
				std::cout << std::left << std::setw(4) << "-";
			else if (board[i][j] == 1)
				std::cout << std::left << std::setw(4) << "X";
			else if (board[i][j] == 2)
				std::cout << std::left << std::setw(4) << "O";
			else
				throw std::invalid_argument("Undefined player representation on game board");
		}
		std::cout << std::endl;
	}
}

bool GameBoard::isWon()
{
	unsigned int count = 0;

	// check diagonals
	if ((board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
		|| (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2))
		count++;
	else if ((board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)
		|| (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2))
		count++;

	// check horizontals
	if ((board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1)
		|| (board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2))
		count++;
	else if ((board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1)
		|| (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2))
		count++;
	else if ((board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1)
		|| (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2))
		count++;

	// check verticals
	if ((board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1)
		|| (board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2))
		count++;
	else if ((board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1)
		|| (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2))
		count++;
	else if ((board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1)
		|| (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2))
		count++;

	if (count > 0)
		return true;
	else
		return false;
}

bool GameBoard::isDraw()
{
	unsigned int count = 0;

	for (unsigned int i = 0; i < board_size; i++)
	{
		for (unsigned int j = 0; j < board_size; j++)
			if (board[i][j] != 0)
				count++;
	}

	if (count == 9)
		return true;
	else
		return false;
}