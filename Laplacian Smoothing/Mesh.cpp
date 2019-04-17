#include "Mesh.h"

Mesh::Mesh() {
	// Default constructor
}

Mesh::~Mesh() {
	for (size_t i = 0; i < vertexList.size(); i++) {
		delete vertexList[i];
	}
}

void Mesh::addVertex(double x, double y, double z) {
	NeighborhoodVertex* vertex = new NeighborhoodVertex(x, y, z);
	vertexList.push_back(vertex);
}

void Mesh::addFace(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {

	vertexList[a]->addNeighbor(vertexList[b]);
	vertexList[b]->addNeighbor(vertexList[c]);
	vertexList[c]->addNeighbor(vertexList[d]);
	vertexList[d]->addNeighbor(vertexList[a]);

	vertexList[a]->addNeighbor(vertexList[d]);
	vertexList[b]->addNeighbor(vertexList[a]);
	vertexList[c]->addNeighbor(vertexList[b]);
	vertexList[d]->addNeighbor(vertexList[c]);

	Face face(a, b, c, d);
	faceList.push_back(face);
	
}

size_t Mesh::getVertexCount() {
	return vertexList.size();
}

size_t Mesh::getFaceCount() {
	return faceList.size();
}

NeighborhoodVertex* Mesh::getVertex(size_t index) {
	return vertexList[index];
}

Face Mesh::getFace(size_t index) {
	return faceList[index];
}

void Mesh::smooth() {
	for (size_t i = 0; i < vertexList.size(); i++) {
		vertexList[i]->updateCoordinates();;
	}
}

void Mesh::setEdgeCount(unsigned int edgeCount) {
	this->edgeCount = edgeCount;
}

unsigned int Mesh::getEdgeCount() {
	return edgeCount;
}
