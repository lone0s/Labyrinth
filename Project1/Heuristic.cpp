#include "Heuristic.h"

bool nothingFront(Grid grid) {

	std::vector<std::vector<Cells>> laby = grid.getLabyrinth();

	switch (grid.getPlayer().getOrientation())
	{
	case up:
		return laby[grid.getPlayer().getY() - 1][grid.getPlayer().getX()] == Cells::EMPTY;
		break;
	case right:
		return laby[grid.getPlayer().getY()][grid.getPlayer().getX() + 1] == Cells::EMPTY;
		break;
	case down:
		return laby[grid.getPlayer().getY() + 1][grid.getPlayer().getX()] == Cells::EMPTY;
		break;
	case left:
		return laby[grid.getPlayer().getY()][grid.getPlayer().getX() - 1] == Cells::EMPTY;
		break;
	default:
		return false;
		break;
	}
}

bool nothingLeft(Grid grid) {

	std::vector<std::vector<Cells>> laby = grid.getLabyrinth();
	int x = grid.getPlayer().getX();
	int y = grid.getPlayer().getY();

	switch (grid.getPlayer().getOrientation())
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

bool nothingRight(Grid grid) {

	std::vector<std::vector<Cells>> laby = grid.getLabyrinth();
	int x = grid.getPlayer().getX();
	int y = grid.getPlayer().getY();

	switch (grid.getPlayer().getOrientation())
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

std::vector<Action> possibleActions(Grid grid) {
	std::vector<Action> actions;
	if (nothingFront(grid)) {
		actions.push_back(Action::GO_FORWARD);
	}
	if (nothingLeft(grid)) {
		actions.push_back(Action::TURN_LEFT);
	}
	if (nothingRight(grid)) {
		actions.push_back(Action::TURN_RIGHT);
	}
	return actions;
}

Action onlyLeft::getNextAction(Grid grid)
{
	if (!nothingFront(grid)) {
		return Action::TURN_LEFT;
	}
	else {
		return Action::GO_FORWARD;
	}
}
