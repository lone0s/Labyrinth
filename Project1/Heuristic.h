#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
class Heuristic
{

public:

	virtual Action getNextAction(Grid grid) = 0;

};

class onlyLeft : public Heuristic
{
public:
	Action getNextAction(Grid grid) override;
};


