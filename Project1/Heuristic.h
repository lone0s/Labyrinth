#pragma once
#include "Action.h"
#include "Grid.h"

#include <stdlib.h>
class Heuristic
{

public:

	virtual std::vector<Action> getNextAction(Grid& grid) = 0;
	//static inline std::vector<Action> availableNextActions(Grid& grid);
};

class onlyLeft : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

class onlyRight : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

class randomCrossroad : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

class choseCrossroad : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};
