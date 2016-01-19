#ifndef GAME_H
#define GAME_H
#include "GameBoard.h"
#include "Human.h"
#include "Computer.h"

class Game
{
public:
	Game();
	void setGame(); // select game type
private:
	const void noComputer(); // human vs. human game loop
	const void yesComputer(); // human vs. computer game loop
	bool isEnd(GameBoard &GB_ref, const unsigned int &player_ID); // check for end of game

	static const unsigned int player_1 = 1;
	static const unsigned int player_2 = 2;
};

#endif