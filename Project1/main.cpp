#include <iostream>
#include <string>
#include "Game.h"

int main()
{

	game game("lab10.txt");

	game.display();

	heuristic* h = new test();
	game.play(*h, true);
}
