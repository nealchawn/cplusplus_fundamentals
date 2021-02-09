#include <iostream>
#include <string>
#include <vector>

struct Vertex {
	float x, y, z;

	Vertex(float xa, float ya, float za) : x(xa), y(ya), z(za) {}

	Vertex(const Vertex& v) 
	: x(v.x), y(v.y), z(v.z)
	{
		std::cout << "I was Copied!" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vert) {
	stream << vert.x << ", " << vert.y << ", " << vert.z;
	return stream;
}

void PrintVec(const std::vector<Vertex>& v) {
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;

	std::cout << "==========" << std::endl;
}

int main() {
	std::vector<Vertex> vertices;
	vertices.reserve(3); // eliminates copies due to resizes

	// vertices.push_back(Vertex(1, 2, 3));
	// with emplace and passing params, the Vector creates the vertex in
	// its memory
	vertices.emplace_back( 1,2,3 );
	vertices.emplace_back(1,2,3 );
	vertices.emplace_back( 4,5,6 );


	std::cout << "==========" << std::endl;

	//PrintVec(vertices);

	std::cin.get();
}