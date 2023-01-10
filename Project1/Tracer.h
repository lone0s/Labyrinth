#pragma once
#include <vector>
#include <tuple>
#include <iostream>
#include "Orientation.h"
class Tracer
{
	std::vector<std::tuple<int,int>> path;

public:
	Tracer() {
		path.push_back(std::make_tuple(1, 1));
	};

	inline void add(const std::tuple<int, int> pos) {
		this->path.push_back(pos);
	};

	inline std::vector<std::tuple<int, int>> getPath() const {
		return this->path;
	};

};

