#pragma once
#include "Grid.h"
#include "Player.h"
#include "Tracer.h"
#include "Heuristic.h"


#pragma once
class Game
{

	Grid grid;
	Player player;
	Tracer tracer;

public:
	Game(std::string file);

	void display();

	void play(Heuristic& heuristic, bool displayed = false);
};

