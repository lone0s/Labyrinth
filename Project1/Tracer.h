#pragma once
#include <vector>
#include "Orientation.h"
class Tracer
{
	std::vector<Orientation> path;

public:
	Tracer();

	void add(Orientation orientation);

	std::vector<Orientation> getPath() const;
};

