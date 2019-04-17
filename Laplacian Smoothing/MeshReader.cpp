#include "MeshReader.h"
#include <fstream>

MeshReader* MeshReader::instance;

MeshReader::MeshReader() {
	instance = new MeshReader();
}

MeshReader::~MeshReader() {
	delete instance;
	instance = 0;
}

MeshReader* MeshReader::getInstance() {
	return instance;
}

void MeshReader::readQuadrilateralMesh(std::string filepath, Mesh* mesh) {

	// Open the file in given location
	std::ifstream infile(filepath);

	// Read the file format
	std::string format;
	infile >> format;

	// Read the mesh information
	unsigned int numVertices, numFaces, numEdges;
	infile >> numVertices >> numFaces >> numEdges;

	// Read the vertices from the file
	for (unsigned int i = 0; i < numVertices; i++) {

		// Read vertex coordinates
		double x, y, z;
		infile >> x >> y >> z;

		// Add a new vertex to the mesh
		mesh->addVertex(x, y, z);
	}

	// Read the faces from the file
	for (unsigned int i = 0; i < numFaces; i++) {

		// Read the number of vertices (always 4 for quadrilateral)
		unsigned int vertexCount;
		infile >> vertexCount;

		// Read the quadrilateral vertices
		unsigned int a, b, c, d;
		infile >> a >> b >> c >> d;

		// Add a new face to the mesh
		mesh->addFace(a, b, c, d);
	}

	// Set the edge count to use later
	mesh->setEdgeCount(numEdges);

	// Close the input file
	infile.close();
}

void MeshReader::writeQuadrilateralMesh(std::string filepath, Mesh* mesh) {

	// Open the file in given location
	std::ofstream outfile(filepath);

	// Write the file format
	outfile << "OFF" << std::endl;

	// Write the mesh information
	outfile << mesh->getVertexCount() << " " << mesh->getFaceCount() << " " << mesh->getEdgeCount() << std::endl;

	// Write each vertex coordinates
	for (unsigned int i = 0; i < mesh->getVertexCount(); i++) {
		NeighborhoodVertex* vertex = mesh->getVertex(i);
		outfile << vertex->x << " " << vertex->y << " " << vertex->z << std::endl;
	}

	// Write each face vertices
	for (unsigned int i = 0; i < mesh->getFaceCount(); i++) {
		Face face = mesh->getFace(i);
		outfile << "4 " << face.a << " " << face.b << " " << face.c << " " << face.d << std::endl;
	}

	// Close the output file
	outfile.close();
}
