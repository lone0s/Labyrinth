#pragma once
#include "Action.h"
#include "Orientation.h"
#include "Tracer.h"
class Player
{
	int x;
	int y;

	Orientation orientation;

	Tracer tracer;

	void turnLeft();
	void turnRight();
	void goForward();
	void turnBack();

	void goUp();
	void goRight();
	void goDown();
	void goLeft();

public:
	Player();

	Tracer getTracer() const {
		return this->tracer;
	}

	int getX() const;
	int getY() const;
	int getOrientation() const;

	char getChar() const;

	void doAction(Action action);

	inline operator size_t() const {
		return this->tracer.getPath().size();
	}

};
