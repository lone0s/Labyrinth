#include "Game.h"
#include <iostream>

#include <chrono>
#include <thread>
Game::Game(std::string file) : grid(file), tracer(), player(tracer) {
}

void Game::display() {

	grid.display(player);

}

void Game::play(Heuristic& heuristic, bool displayed) {

	size_t cpt = 0;
	while (!grid.isExit(player)) {
		++cpt;

		player.doAction(heuristic.getNextAction(player, grid));

		if (displayed) {
			display();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}

		if (cpt > 1000) {
			std::cout << "You may be stuck in a loop, do you want to continue ? (y/n)" << std::endl;
			char c;
			std::cin >> c;
			if (c == 'n')
				break;
			else
				cpt = 0;
		}


	}

	if (grid.isExit(player)) {
		std::cout << "Player reached the exit" << std::endl;

		std::cout << "Number of moves: " << tracer.getPath().size() << std::endl;
	}
	else
		std::cout << "Player haven't reached the exit" << std::endl;

}