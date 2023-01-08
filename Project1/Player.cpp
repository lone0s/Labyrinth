#include "Player.h"
Player::Player(Tracer& t) : t(&t), orientation(right), x(1), y(1) {}


int Player::getX() const {
	return x;
}

int Player::getY() const {
	return y;
}

int Player::getOrientation() const {
	return orientation;
}


char Player::getChar() const {
	switch (orientation)
	{
	case up:
		return '^';
		break;
	case right:
		return '>';
		break;
	case down:
		return 'v';
		break;
	case left:
		return '<';
		break;
	default:
		return '?';
		break;
	}
}

void Player::goForward() {
	t->add(orientation);
	switch (orientation)
	{
	case up:
		y--;
		break;
	case right:
		x++;
		break;
	case down:
		y++;
		break;
	case left:
		x--;
		break;
	default:
		break;
	}
}

void Player::turnLeft() {
	orientation = Orientation(((orientation + 3) % 4));
}

void Player::turnRight() {
	orientation = Orientation(((orientation + 1) % 4));
}

void Player::turnBack() {
	orientation = Orientation(((orientation + 2) % 4));
}

void Player::doAction(Action action) {

	switch (action)
	{
	case Action::TURN_LEFT:
		this->turnLeft();
		break;
	case Action::TURN_RIGHT:
		this->turnRight();
		break;
	case Action::GO_FORWARD:
		this->goForward();
		break;
	default:
		break;
	}

}