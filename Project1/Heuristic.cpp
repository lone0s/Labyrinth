#include <tuple>
#include "Heuristic.h"

#pragma once

std::vector<Action> onlyLeft::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
	if (!grid.playerHasNothingInFront()) {
		nextActions.push_back(Action::TURN_LEFT);
	}
	else {
		nextActions.push_back(Action::GO_FORWARD);
	}
	return nextActions;
	//std::vector<Action> actions = possibleActions(grid);
	//if (std::find(actions.begin(), actions.end(), Action::GO_FORWARD) != actions.end())
	//	return Action::GO_FORWARD;
	//else if (std::find(actions.begin(), actions.end(), Action::TURN_LEFT) != actions.end())
	//	return Action::TURN_LEFT;
}

std::vector<Action> onlyRight::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
	if (!grid.playerHasNothingInFront()) {
		nextActions.push_back(Action::TURN_RIGHT);
	}
	else {
		nextActions.push_back(Action::GO_FORWARD);
	}
	return nextActions;
}

std::vector<Action> randomCrossroad::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
	std::vector<Action> actions = grid.possibleActions();
	
	if (actions.size() == 1) {
		nextActions.push_back(actions[0]);
	}
	else {
		int random = rand() % actions.size();
		nextActions.push_back(actions[random]);
		if (actions[random] != Action::GO_FORWARD) {
			nextActions.push_back(Action::GO_FORWARD);
		}
	}
	return nextActions;
}

std::vector<Action> choseCrossroad::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
	std::vector<Action> actions = grid.possibleActions();
	if (actions.size() == 1) {
		nextActions.push_back(actions[0]);
		if (nextActions[0] != Action::GO_FORWARD) {
			nextActions.push_back(Action::GO_FORWARD);
		}
	}
	else {
		//ask in the console which action to take
		//display the possible actions
		std::cout << "Possible actions: " << std::endl;
		for (int i = 0; i < actions.size(); i++) {
			if (actions[i] == Action::GO_FORWARD) {
				std::cout << i << " : Go forward" << std::endl;
			}
			else if (actions[i] == Action::TURN_LEFT) {
				std::cout << i << " : Turn left" << std::endl;
			}
			else if (actions[i] == Action::TURN_RIGHT) {
				std::cout << i << " : Turn right" << std::endl;
			}
			else if (actions[i] == Action::TURN_BACK) {
				std::cout << i << " : Turn back" << std::endl;
			}
		}
		//ask the user to choose an action
		int choice;
		std::cout << "Choose an action: ";
		std::cin >> choice;
		//return the action
		nextActions.push_back(actions[choice]);
		if (actions[choice] != Action::GO_FORWARD) {
			nextActions.push_back(Action::GO_FORWARD);
		};
	}
	return nextActions;
}