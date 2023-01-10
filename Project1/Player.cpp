#include "Player.h"
Player::Player() : tracer(), orientation(right), x(1), y(1) {}


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
	tracer.add(orientation);
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

void Player::goUp() {
	y--;
	orientation = up;
}

void Player::goRight() {
	x++;
	orientation = right;
}

void Player::goDown() {
	y++;
	orientation = down;
}

void Player::goLeft() {
	x--;
	orientation = left;
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
	case Action::TURN_BACK:
		this->turnBack();
		break;
	case Action::GO_UP:
		this->goUp();
		break;
	case Action::GO_RIGHT:
		this->goRight();
		break;
	case Action::GO_DOWN:
		this->goDown();
		break;
	case Action::GO_LEFT:
		this->goLeft();
		break;
	default:
		break;
	}

}