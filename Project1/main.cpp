#include <iostream>
#include <string>
#include "Game.h"

int main()
{
	Game game("../TestFiles/lab3.txt");

	Heuristic* h = new randomCrossroad();
	game.play(*h, true);
}
