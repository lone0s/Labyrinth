#include <iostream>
#include <string>
#include "Game.h"

int main()
{

	Game game("lab10.txt");

	game.display();

	Heuristic* h = new onlyLeft();
	game.play(*h, true);

}