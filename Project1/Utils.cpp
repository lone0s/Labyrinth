//inline Action positionToAction(const std::tuple<int, int>& availablePosition, Grid& grid) {
//	Player player = grid.getPlayer();
//	int userX = player.getX();
//	int userY = player.getY();
//	int availableX = std::get<0>(availablePosition);
//	int availableY = std::get<1>(availablePosition);
//	switch (player.getOrientation()) {
//	case up:
//		if (availableY - userY == -1) {
//			return Action::GO_FORWARD;
//		}
//		else if (availableX - userX == 1) {
//			return Action::TURN_RIGHT;
//		}
//		else if (availableX - userX == -1) {
//			return Action::TURN_LEFT;
//		}
//		else if (availableY - userY == 1) {
//			return Action::TURN_BACK;
//		}
//		break;
//	case right:
//		if (availableX - userX == 1) {
//			return Action::GO_FORWARD;
//		}
//		else if (availableY - userY == 1) {
//			return Action::TURN_RIGHT;
//		}
//		else if (availableY - userY == -1) {
//			return Action::TURN_LEFT;
//		}
//		else if (availableX - userX == -1) {
//			return Action::TURN_BACK;
//		}
//		break;
//	case down:
//		if (availableY - userY == 1) {
//			return Action::GO_FORWARD;
//		}
//		else if (availableX - userX == -1) {
//			return Action::TURN_RIGHT;
//		}
//		else if (availableX - userX == 1) {
//			return Action::TURN_LEFT;
//		}
//		else if (availableY - userY == -1) {
//			return Action::TURN_BACK;
//		}
//		break;
//	case left:
//		if (availableX - userX == -1) {
//			return Action::GO_FORWARD;
//		}
//		else if (availableY - userY == -1) {
//			return Action::TURN_RIGHT;
//		}
//		else if (availableY - userY == 1) {
//			return Action::TURN_LEFT;
//		}
//		else if (availableX - userX == 1) {
//			return Action::TURN_BACK;
//		}
//		break;
//	}
//}
//
//inline std::vector<Action> Heuristic::availableNextActions(Grid& grid) {
//	std::vector<std::vector<Cells>> laby = grid.getLabyrinth();
//
//	int userX = grid.getPlayer().getX();
//	int userY = grid.getPlayer().getX();
//
//	std::vector<std::tuple<int, int>> availablePositions;
//
//	if (laby[userX + 1][userY] == Cells::EMPTY) {
//		availablePositions.push_back(std::make_tuple(userX + 1, userY));
//	}
//	if (laby[userX - 1][userY] == Cells::EMPTY) {
//		availablePositions.push_back(std::make_tuple(userX - 1, userY));
//	}
//	if (laby[userX][userY + 1] == Cells::EMPTY) {
//		availablePositions.push_back(std::make_tuple(userX, userY + 1));
//	}
//	if (laby[userX][userY - 1] == Cells::EMPTY) {
//		availablePositions.push_back(std::make_tuple(userX, userY - 1));
//	}
//
//	std::vector<Action> availableActions;
//	for (std::tuple<int, int>& position : availablePositions) {
//		availableActions.push_back(positionToAction(position, grid));
//	}
//
//	return availableActions;
//}