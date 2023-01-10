#include <tuple>
#include "Heuristic.h"

#pragma once

Action onlyLeft::getNextAction(Grid& grid)
{
	if (!grid.playerHasNothingInFront()) {
		return Action::TURN_LEFT;
	}
	else {
		return Action::GO_FORWARD;
	}
	//std::vector<Action> actions = possibleActions(grid);
	//if (std::find(actions.begin(), actions.end(), Action::GO_FORWARD) != actions.end())
	//	return Action::GO_FORWARD;
	//else if (std::find(actions.begin(), actions.end(), Action::TURN_LEFT) != actions.end())
	//	return Action::TURN_LEFT;
}
