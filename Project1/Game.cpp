#include "Game.h"
#include <iostream>

#include <chrono>
#include <thread>
Game::Game(const std::string& file) : grid(file), cpt(0) {}

void Game::display() {
	grid.display();
}

void Game::play(Heuristic& heuristic, bool displayed, bool notEpileptic) {
	while (!this->grid.isExit()) {
		++cpt;
		for (Action action : heuristic.getNextAction(this->grid)) {
			grid.getPlayer().doAction(action);
		}

		if (displayed) {
			display();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			if (notEpileptic){
				system("cls");
			}
		}

		if (cpt > 1000000) {
			std::cout << "You may be stuck in a loop, do you want to continue ? (y/n)" << std::endl;
			char c;
			std::cin >> c;
			if (c == 'n')
				break;
			else
				cpt = 0;
		}

		if (cpt % 10000 == 0) {
			std::cout << cpt << std::endl;
			display();
		}
			
	}

	if (grid.isExit()) {
		std::cout << "Player reached the exit" << std::endl;
		std::cout << "Number of moves: " << (size_t)grid.getPlayer()<< std::endl;
	}
	else
		std::cout << "Player haven't reached the exit" << std::endl;

}