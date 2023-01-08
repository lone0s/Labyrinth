#pragma once
#include "Action.h"
#include "Orientation.h"
#include "Tracer.h"
class Player
{
	int x;
	int y;

	Orientation orientation;

	Tracer* t;

	void turnLeft();
	void turnRight();
	void goForward();

public:
	Player(Tracer& t);

	int getX() const;
	int getY() const;
	int getOrientation() const;

	char getChar() const;

	void turnBack();

	void doAction(Action action);


};
