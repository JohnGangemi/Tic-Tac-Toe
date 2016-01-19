#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <string>

class GameBoard
{
	friend class Human;
	friend class Computer;
public:
	GameBoard(); // initialize game board
	const int getGameState(); // return game state; -1(draw), 0(neither), 1(win)
	const void displayGameBoard(); // print state of game board
private:
	bool isWon(); // check for win
	bool isDraw(); // check for draw

	static const unsigned int board_size = 3;
	static const unsigned int positions_size = 9;
	static const std::string positions[positions_size]; // row & column string literals
	unsigned int board[board_size][board_size]; // 3 by 3 game board
};

#endif