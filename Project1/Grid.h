#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream> 
#include "Cells.h"
#include "Player.h"

enum class Cells {
	EMPTY,
	WALL,
	EXIT
};

class Grid
{
	std::vector<std::vector<Cells>> labyrinth;
	char wallChar;
	char emptyChar;

	Player player;

	size_t width;
	size_t height;


public:
	explicit Grid(const std::string& file, char wallChar = '#', char emptyChar = ' ');

	inline Player& getPlayer() {
		return this->player;
	};

	void display() const;

	bool isExit() const;

	const bool playerHasNothingInFront();
	const bool playerHasNothingInLeft();
	const bool playerHasNothingInRight();
	const std::vector<Action> possibleRelativeActions();
	const bool checkAbsoluteActions(Action action);
	
	std::vector<std::vector<Cells>> getLabyrinth() const;
};

