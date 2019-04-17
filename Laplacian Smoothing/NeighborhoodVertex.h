#ifndef NEIGHBORHOOD_VERTEX
#define NEIGHBORHOOD_VERTEX

#include <vector>
#include "Vertex.h"

class NeighborhoodVertex : public Vertex {
public:

	NeighborhoodVertex(double x = 0.0f, double y = 0.0f, double z = 0.0f);

	void addNeighbor(NeighborhoodVertex* vertex);
	void updateCoordinates();

private:

	std::vector<NeighborhoodVertex*> neighborList;

};

#endif
