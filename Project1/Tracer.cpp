#include "Tracer.h"
Tracer::Tracer() {}

void Tracer::add(Orientation orientation) {
	path.push_back(orientation);
}

std::vector<Orientation> Tracer::getPath() const {
	return path;
}