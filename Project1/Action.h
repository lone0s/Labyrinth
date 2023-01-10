#pragma once
#include <iostream>

enum class Action {
    //relative directions
    TURN_LEFT,
    TURN_RIGHT,
    GO_FORWARD,
    TURN_BACK,
    
	//absolute directions
    GO_UP,
	GO_DOWN,
    GO_RIGHT,
	GO_LEFT,

    //other
    INVALID
};

inline std::ostream& operator<<(std::ostream& out, const Action& action) {
    switch (action) {
        case Action::TURN_LEFT:
            out << "turn left";
            break;
        case Action::TURN_RIGHT:
			out << "turn right";
            break;
        case Action::GO_FORWARD:
			out << "go forward";
            break;
        case Action::TURN_BACK:
			out << "turn back";
            break;
    }
    return out;
}
