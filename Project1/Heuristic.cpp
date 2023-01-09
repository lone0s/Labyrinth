#include "Heuristic.h"

bool nothingFront(Player player, Grid grid) {

	std::vector<std::vector<Cells>> laby = grid.getLabyrinth();
	
	int x = player.getX();
	int y = player.getY();
	
	switch (player.getOrientation())
	{
	case up:
		return laby[y - 1][x] == Cells::EMPTY;
		break;
	case right:
		return laby[y][x + 1] == Cells::EMPTY;
		break;
	case down:
		return laby[y + 1][x] == Cells::EMPTY;
		break;
	case left:
		return laby[y][x - 1] == Cells::EMPTY;
		break;
	default:
		return false;
		break;
	}
}

bool nothingLeft(Player player, Grid grid) {

	std::vector<std::vector<Cells>> laby = grid.getLabyrinth();
	int x = player.getX();
	int y = player.getY();

	switch (player.getOrientation())
	{
	case up:
		return laby[y][x - 1] == Cells::WALL;
		break;
	case right:
		return laby[y + 1][x] == Cells::WALL;
		break;
	case down:
		return laby[y][x + 1] == Cells::WALL;
		break;
	case left:
		return laby[y - 1][x] == Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

bool nothingRight(Player player, Grid grid) {

	std::vector<std::vector<Cells>> laby = grid.getLabyrinth();
	int x = player.getX();
	int y = player.getY();

	switch (player.getOrientation())
	{
	case up:
		return laby[y][x + 1] == Cells::WALL;
		break;
	case right:
		return laby[y - 1][x] == Cells::WALL;
		break;
	case down:
		return laby[y][x - 1] == Cells::WALL;
		break;
	case left:
		return laby[y + 1][x] == Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

std::vector<Action> possibleActions(Player player, Grid grid) {
	std::vector<Action> actions;
	if (nothingFront(player, grid)) {
		actions.push_back(Action::GO_FORWARD);
	}
	if (nothingLeft(player, grid)) {
		actions.push_back(Action::TURN_LEFT);
	}
	if (nothingRight(player, grid)) {
		actions.push_back(Action::TURN_RIGHT);
	}
	return actions;
}

Action onlyLeft::getNextAction(Player player, Grid grid)
{
	if (!nothingFront(player, grid)) {
		return Action::TURN_LEFT;
	}
	else {
		return Action::GO_FORWARD;
	}
}
