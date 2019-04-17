#include "NeighborhoodVertex.h"

NeighborhoodVertex::NeighborhoodVertex(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void NeighborhoodVertex::addNeighbor(NeighborhoodVertex* vertex) {
	neighborList.push_back(vertex);
}

void NeighborhoodVertex::updateCoordinates() {

	double totalX = 0;
	double totalY = 0;
	double totalZ = 0;

	size_t neighborCount = neighborList.size();
	for (size_t i = 0; i < neighborCount; i++) {
		NeighborhoodVertex* neighbor = neighborList[i];
		totalX += neighbor->x;
		totalY += neighbor->y;
		totalZ += neighbor->z;
	}

	x = totalX / neighborCount;
	y = totalY / neighborCount;
	z = totalZ / neighborCount;
}
