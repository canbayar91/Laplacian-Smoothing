#ifndef VERTEX
#define VERTEX

class Vertex {
public:

	double x;
	double y;
	double z;

	Vertex(double x = 0.0f, double y = 0.0f, double z = 0.0f);
	Vertex(const Vertex &vertex);

	Vertex &operator=(const Vertex &vertex);

	Vertex operator+(const Vertex &vertex) const;
	Vertex operator-(const Vertex &vertex) const;
	Vertex operator*(const double value) const;
	Vertex operator*(const Vertex &vertex) const;
	Vertex operator/(const double value) const;

	Vertex &operator+=(const Vertex &vertex);
	Vertex &operator-=(const Vertex &vertex);
	Vertex &operator*=(const double value);
	Vertex &operator*=(const Vertex &vertex);
	Vertex &operator/=(const double value);

};

#endif
