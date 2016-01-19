#ifndef COMPUTER_H
#define COMPUTER_H
#include "GameBoard.h"
#include <vector>

class Computer
{
public:
	Computer(const unsigned int &player_ID = 2); // set player identification
	void makeMove(GameBoard &GB);  // make move
private:
	void defensiveMove(const GameBoard &GB_ref); // possible denfensive moves
	void setDifficulty(); // set computer's difficulty level

	unsigned int player;
	unsigned int difficulty;
	std::vector<int> moves; // store defensive moves
};

#endif