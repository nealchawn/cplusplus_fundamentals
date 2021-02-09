#include <iostream>
#include <string>
#include <vector>

struct Vertex {
	float x, y, z;
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
	
	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 });

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	std::cout << "==========" << std::endl;

	PrintVec(vertices);

	//vertices.clear();
	vertices.erase(vertices.begin() + 1); // vertices.begin() returns an iterator at first; + 1 gives the second element

	for (const Vertex& v : vertices)
		std::cout << v << std::endl;

	std::cin.get();
}