#include "Game.h"
#include <iostream>

#include <chrono>
#include <thread>
Game::Game(const std::string& file) : grid(file){
}

void Game::display() {
	grid.display();
}

void Game::play(Heuristic& heuristic, bool displayed) {
	size_t cpt = 0;
	while (!this->grid.isExit()) {
		++cpt;

		grid.getPlayer().doAction(heuristic.getNextAction(grid));

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

	if (grid.isExit()) {
		std::cout << "Player reached the exit" << std::endl;

		std::cout << "Number of moves: " << (size_t)grid.getPlayer()<< std::endl;
	}
	else
		std::cout << "Player haven't reached the exit" << std::endl;

}