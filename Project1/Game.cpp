#include "Game.h"
#include <iostream>

#include <chrono>
#include <thread>
Game::Game(const std::string& file) : grid(file), cpt(0) {}

void Game::display() {
	grid.display();
}

void Game::play(Heuristic& heuristic, bool displayed) {
	while (!this->grid.isExit()) {

		if (displayed) {
			display();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

		
		++cpt;
		for (Action action : heuristic.getNextAction(this->grid)) {
			grid.getPlayer().doAction(action);
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
		if (displayed) {
			display();
		}
		std::cout << "\nPlayer reached the exit" << std::endl;
		std::cout << "Number of moves: " << (size_t)grid.getPlayer()<< std::endl;
		
		std::cout << "\n Path used : " << std::endl;
		grid.displayPath();
		
	}
	else
		std::cout << "Player haven't reached the exit" << std::endl;

}