#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream> 
#include "Cells.h"
#include "Player.h"

class Grid
{
	std::vector<std::vector<Cells>> labyrinth;
	char wallChar;
	char emptyChar;

	size_t width;
	size_t height;


public:
	Grid(std::string file, char wallChar = '#', char emptyChar = ' ');

	void display(Player player);

	bool isExit(Player player);

	std::vector<std::vector<Cells>> getLabyrinth() const;
};

