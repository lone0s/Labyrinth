#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
class Heuristic
{

public:

	virtual Action getNextAction(Player player, Grid grid) = 0;

};

class onlyLeft : public Heuristic
{
public:
	Action getNextAction(Player player, Grid grid) override;
};


