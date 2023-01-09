#include "Grid.h"


Grid::Grid(std::string file, char wallChar, char emptyChar) : wallChar(wallChar), emptyChar(emptyChar) {
	std::ifstream infile(file);
	std::string line;

	if (infile.is_open()) {
		std::vector<Cells> row;
		while (std::getline(infile, line)) {

			for (int i = 0; i < line.length(); i++) {
				if (line[i] == emptyChar) {
					row.push_back(Cells::EMPTY);
				}
				else if (line[i] == wallChar) {
					row.push_back(Cells::WALL);
				}
				else {
					std::cerr << "Error, invalid char \" "
						<< line[i]
						<< " \" found in text file"
						<< std::endl;
				}
			}
			labyrinth.push_back(row);
			row.clear();
		}
		infile.close();
	}
	else {
		std::cerr << "Unable to open file" << std::endl;
	}
	width = labyrinth[0].size();
	height = labyrinth.size();


	labyrinth[height - 2][width - 2] = Cells::EXIT;
	labyrinth[0][0] = Cells::WALL;
	labyrinth[0][1] = Cells::WALL;
	labyrinth[0][2] = Cells::WALL;
	labyrinth[1][0] = Cells::WALL;
	//Pq tu fais ça ?
	labyrinth[height - 1].push_back(Cells::WALL);
	labyrinth[height - 2].push_back(Cells::WALL);
}

void Grid::display(Player player) {
	std::stringstream ss;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < labyrinth[y].size(); ++x) {
			if (player.getX() == x && player.getY() == y) {
				ss << player.getChar();
			}
			else if (labyrinth[y][x] == Cells::WALL) {
				ss << wallChar;
			}
			else if (labyrinth[y][x] == Cells::EXIT) {
				ss << '@';
			}
			else {
				ss << emptyChar;
			}
		}
		ss << std::endl;
	}
	std::cout << ss.str();
}


bool Grid::isExit(Player player) {
	return labyrinth[player.getY()][player.getX()] == Cells::EXIT;
}


std::vector<std::vector<Cells>> Grid::getLabyrinth() const {
	return labyrinth;
}