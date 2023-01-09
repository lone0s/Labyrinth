#pragma once
#include <vector>
#include "Orientation.h"
class Tracer
{
	std::vector<Orientation> path;

public:
	Tracer() {};

	inline void add(const Orientation orientation) {
		this->path.push_back(orientation);
	};

	inline std::vector<Orientation> getPath() const {
		return this->path;
	};
};

