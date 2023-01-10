#include "Grid.h"


Grid::Grid(const std::string& file, char wallChar, char emptyChar) : wallChar(wallChar), emptyChar(emptyChar), player() {
	
	std::ifstream infile(file);
	
	std::string line;

	if (infile.is_open()) {

		std::vector<Cells> row;
		while (std::getline(infile, line)) {
			int cpt = 1;
			for (int i = 0; i < line.length(); i++) {
				++cpt;
				if (cpt % 3 != 0) {
					if (line[i] == emptyChar)
						row.push_back(Cells::EMPTY);
					else if (line[i] == wallChar)
						row.push_back(Cells::WALL);
					else{
						//std::cerr << "Error, invalid char found in file : " << line[i] << std::endl;
						//exit(1);
						throw std::exception();
					}
				}
			}
			labyrinth.push_back(row);
			row.clear();
		}
		infile.close();

		width = labyrinth[0].size();
		height = labyrinth.size();


		labyrinth[height - 2][width - 2] = Cells::EXIT;
		labyrinth[0][0] = Cells::WALL;
		labyrinth[0][1] = Cells::WALL;

		labyrinth[0][2] = Cells::WALL;
		labyrinth[1][0] = Cells::WALL;
	}
	else {
		//std::cerr << "Unable to open file " + file << std::endl;
		//exit(1);
		throw std::exception();
	}

}

void Grid::display() const{
	std::stringstream ss;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < labyrinth[y].size(); ++x) {
			if (this->player.getX() == x && this->player.getY() == y) {
				ss << this->player.getChar();
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


bool Grid::isExit() const{
	return labyrinth[this->player.getY()][this->player.getX()] == Cells::EXIT;
}


std::vector<std::vector<Cells>> Grid::getLabyrinth() const {
	return labyrinth;
}

const bool Grid::playerHasNothingInFront(){
	std::vector<std::vector<Cells>> laby = getLabyrinth();
	const Player player = getPlayer();;
	int x = getPlayer().getX();
	int y = getPlayer().getY();

	switch (player.getOrientation())
	{
	case up:
		return laby[y - 1][x] != Cells::WALL;
		break;
	case right:
		return laby[y][x + 1] != Cells::WALL;
		break;
	case down:
		return laby[y + 1][x] != Cells::WALL;
		break;
	case left:
		return laby[y][x - 1] != Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

const bool Grid::playerHasNothingInLeft() {
	std::vector<std::vector<Cells>> laby = getLabyrinth();
	const Player player = getPlayer();;
	const int x = getPlayer().getX();
	const int y = getPlayer().getY();

	switch (player.getOrientation())
	{
	case up:
		return laby[y][x - 1] != Cells::WALL;
		break;
	case right:
		return laby[y - 1][x] != Cells::WALL;
		break;
	case down:
		return laby[y][x + 1] != Cells::WALL;
		break;
	case left:
		return laby[y + 1][x] != Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

const bool Grid::playerHasNothingInRight() {
	std::vector<std::vector<Cells>> laby = getLabyrinth();
	const Player player = getPlayer();;
	const int x = getPlayer().getX();
	const int y = getPlayer().getY();

	switch (player.getOrientation())
	{
	case up:
		return laby[y][x + 1] != Cells::WALL;
		break;
	case right:
		return laby[y + 1][x] != Cells::WALL;
		break;
	case down:
		return laby[y][x - 1] != Cells::WALL;
		break;
	case left:
		return laby[y - 1][x] != Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

const std::vector<Action> Grid::possibleRelativeActions() {
	std::vector<Action> actions;

	if (playerHasNothingInFront()) {
		actions.push_back(Action::GO_FORWARD);
	}
	if (playerHasNothingInLeft()) {
		actions.push_back(Action::TURN_LEFT);
	}
	if (playerHasNothingInRight()) {
		actions.push_back(Action::TURN_RIGHT);
	}
	if (actions.size() == 0) {
		actions.push_back(Action::TURN_BACK);
	}
	return actions;
}

const bool Grid::checkAbsoluteActions(Action action) {
	
	std::vector<Action> actions;
	
	int x = getPlayer().getX();
	int y = getPlayer().getY();
	
	switch (action)
	{
	case Action::GO_UP:
		return labyrinth[y - 1][x] != Cells::WALL;
		break;
	case Action::GO_RIGHT:
		return labyrinth[y][x + 1] != Cells::WALL;
		break;
	case Action::GO_DOWN:
		return labyrinth[y + 1][x] != Cells::WALL;
		break;
	case Action::GO_LEFT:
		return labyrinth[y][x - 1] != Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

const void Grid::displayPath() {
	std::vector<std::tuple<int,int>> path = player.getTracer().getPath();
	
	std::vector<std::vector<Cells>> laby = getLabyrinth();
	
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < labyrinth[y].size(); ++x) {
			std::tuple<int, int> pos = std::make_tuple(x, y);
			
			if (laby[y][x] == Cells::WALL) {
				std::cout << wallChar;
			}
			else if (laby[y][x] == Cells::EXIT) {
				std::cout << '@';
			}
			else if (std::find(path.begin(), path.end(), pos) != path.end()) {
				std::cout << '*';
			}
			else {
				std::cout << emptyChar;
			}
		}
		std::cout << std::endl;
	}
	
	
}
