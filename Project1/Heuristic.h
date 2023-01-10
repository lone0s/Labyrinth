#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
class Heuristic
{

public:

	virtual Action getNextAction(Grid& grid) = 0;
	//static inline std::vector<Action> availableNextActions(Grid& grid);
};

class onlyLeft : public Heuristic
{
public:
	Action getNextAction(Grid& grid) override;
};


