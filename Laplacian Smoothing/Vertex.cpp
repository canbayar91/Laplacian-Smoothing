#include "Vertex.h"

Vertex::Vertex(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vertex::Vertex(const Vertex &vertex) {
	*this = vertex;
}

Vertex &Vertex::operator=(const Vertex &vertex) {
	if (this != &vertex) {
		this->x = vertex.x;
		this->y = vertex.y;
		this->z = vertex.z;
	}

	return *this;
}

Vertex Vertex::operator+(const Vertex &vertex) const {
	return Vertex(x + vertex.x, y + vertex.y, z + vertex.z);
}

Vertex Vertex::operator-(const Vertex &vertex) const {
	return Vertex(x - vertex.x, y - vertex.y, z - vertex.z);
}

Vertex Vertex::operator*(const double value) const {
	return Vertex(value * x, value * y, value * z);
}

Vertex Vertex::operator*(const Vertex &vertex) const {
	return Vertex(x * vertex.x, y * vertex.y, z * vertex.z);
}

Vertex Vertex::operator/(const double value) const {
	double r = double(1.0) / value;
	return *this * r;
}

Vertex &Vertex::operator+=(const Vertex &vertex) {
	x += vertex.x;
	y += vertex.y;
	z += vertex.z;
	return *this;
}

Vertex &Vertex::operator-=(const Vertex &vertex) {
	x -= vertex.x;
	y -= vertex.y;
	z -= vertex.z;
	return *this;
}

Vertex &Vertex::operator*=(const double value) {
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vertex &Vertex::operator*=(const Vertex &vertex) {
	x *= vertex.x;
	y *= vertex.y;
	z *= vertex.z;
	return *this;
}

Vertex &Vertex::operator/=(const double value) {
	double r = double(1.0) / value;
	*this *= r;
	return *this;
}
