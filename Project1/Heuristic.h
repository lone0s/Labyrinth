#pragma once
#include "Action.h"
#include "Grid.h"

#include <stdlib.h>
#include <Windows.h>

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

class chooseCrossroad : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};


class chooseAll : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};

class stairs : public Heuristic
{
public:
	std::vector<Action> getNextAction(Grid& grid) override;
};