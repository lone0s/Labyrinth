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
	std::vector<Action> actions = grid.possibleRelativeActions();
	
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

std::vector<Action> chooseCrossroad::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
	std::vector<Action> actions = grid.possibleRelativeActions();
	if (actions.size() == 1) {
		
		nextActions.push_back(actions[0]);
		if (nextActions[0] != Action::GO_FORWARD) {
			nextActions.push_back(Action::GO_FORWARD);
		}
	}
	else {
		std::cout << "Use arrow keys to move " << std::endl;
		Action choice = Action::INVALID;
		
		while (choice == Action::INVALID) {
			if (GetAsyncKeyState(VK_UP) & 0x8000) {   // arrow up key
				choice = Action::GO_UP;
			}
			else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {    // arrow left key
				choice = Action::GO_LEFT;
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {   // arrow right key
				choice = Action::GO_RIGHT;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {   // arrow down key
				choice = Action::GO_DOWN;
			}
			
			if (grid.checkAbsoluteActions(choice)) {
				nextActions.push_back(choice);
			}
			else {
				choice = Action::INVALID;
			}
		};
	}
	return nextActions;
}

std::vector<Action> chooseAll::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;

	std::cout << "Use arrow keys to move" << std::endl;
	
	Action choice = Action::INVALID;
	while (choice == Action::INVALID) {
		if (GetAsyncKeyState(VK_UP) & 0x8000) {   // arrow up key
			choice = Action::GO_UP;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {    // arrow left key
			choice = Action::GO_LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {   // arrow right key
			choice = Action::GO_RIGHT;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {   // arrow down key
			choice = Action::GO_DOWN;
		}
		if (grid.checkAbsoluteActions(choice)) {
			nextActions.push_back(choice);
		}
		else {
			choice = Action::INVALID;
		}
	}
	
	return nextActions;
}

std::vector<Action> stairs::getNextAction(Grid& grid)
{
	std::vector<Action> nextActions;
		
	std::vector<Action> actions = grid.possibleRelativeActions();
	
	if (actions.size() == 1) {
		nextActions.push_back(actions[0]);
	}
	else {
		
		int x = grid.getPlayer().getX();
		int y = grid.getPlayer().getY();

		if (x >= y) {
			if (grid.checkAbsoluteActions(Action::GO_DOWN)) 
				nextActions.push_back(Action::GO_DOWN);
			else if (grid.checkAbsoluteActions(Action::GO_RIGHT))
				nextActions.push_back(Action::GO_RIGHT);
			else if (grid.checkAbsoluteActions(Action::GO_LEFT))
				nextActions.push_back(Action::GO_LEFT);
			else if (grid.checkAbsoluteActions(Action::GO_UP))
				nextActions.push_back(Action::GO_UP);
		}
		else {
			if (grid.checkAbsoluteActions(Action::GO_RIGHT))
				nextActions.push_back(Action::GO_RIGHT);
			else if (grid.checkAbsoluteActions(Action::GO_DOWN))
				nextActions.push_back(Action::GO_DOWN);
			else if (grid.checkAbsoluteActions(Action::GO_LEFT))
				nextActions.push_back(Action::GO_LEFT);
			else if (grid.checkAbsoluteActions(Action::GO_UP))
				nextActions.push_back(Action::GO_UP);
		}
	}
	return nextActions;
}