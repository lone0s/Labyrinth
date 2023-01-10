#include <iostream>
#include <string>
#include "Game.h"

int main()
{
	Game game("../TestFiles/lab3.txt");
	game.display();
	Heuristic* h = new choseCrossroad();
	game.play(*h, true, false);
}
