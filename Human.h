#ifndef HUMAN_H
#define HUMAN_H
#include "GameBoard.h"

class Human
{
public:
	Human(const unsigned int &player_ID = 1); // set player identification
	void makeMove(GameBoard &GB); // make move
private:
	const unsigned int validateMove(const GameBoard &GB_ref); // validate user move

	unsigned int player;
};

#endif