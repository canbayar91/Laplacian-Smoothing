#ifndef MESH
#define MESH

#include "NeighborhoodVertex.h"

struct Face {

	Face(unsigned int a = 0, unsigned int b = 0, unsigned int c = 0, unsigned int d = 0) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
};

class Mesh {
public:

	Mesh();
	~Mesh();

	void addVertex(double x, double y, double z);
	void addFace(unsigned int a, unsigned int b, unsigned int c, unsigned int d);

	size_t getVertexCount();
	size_t getFaceCount();

	NeighborhoodVertex* getVertex(size_t index);
	Face getFace(size_t index);

	void smooth();

	void setEdgeCount(unsigned int edgeCount);
	unsigned int getEdgeCount();

private:

	std::vector<NeighborhoodVertex*> vertexList;
	std::vector<Face> faceList;

	unsigned int edgeCount;

};

#endif
