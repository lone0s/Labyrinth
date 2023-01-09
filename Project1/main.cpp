#include <iostream>
#include <string>
#include "Game.h"

int main()
{

	Game game("../TestFiles/lab10.txt");

	game.display();

	Heuristic* h = new onlyLeft();
	game.play(*h, true);
}
