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
	explicit Grid(std::string file, char wallChar = '#', char emptyChar = ' ');

	inline Player getPlayer() const {
		return this->player;
	};

	void display();

	bool isExit();

	std::vector<std::vector<Cells>> getLabyrinth() const;
};

