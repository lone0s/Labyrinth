#include "Heuristic.h"

bool isFacingWall(Player player, Grid grid) {

	std::vector<std::vector<Cells>> laby = grid.getLabyrinth();

	switch (player.getOrientation())
	{
	case up:
		return laby[player.getY() - 1][player.getX()] == Cells::WALL;
		break;
	case right:
		return laby[player.getY()][player.getX() + 1] == Cells::WALL;
		break;
	case down:
		return laby[player.getY() + 1][player.getX()] == Cells::WALL;
		break;
	case left:
		return laby[player.getY()][player.getX() - 1] == Cells::WALL;
		break;
	default:
		return false;
		break;
	}
}

Action onlyLeft::getNextAction(Player player, Grid grid)
{
	if (isFacingWall(player, grid)) {
		return Action::TURN_LEFT;
	}
	else {
		return Action::GO_FORWARD;
	}
}