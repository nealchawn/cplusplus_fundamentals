#include <iostream>

struct Entity {
	int x, y;

	int* get_positions() {
		return &x;
	}
};


int main() {
	
	// Type Punning: I'm going to treat this memory that I have different that what it is!
	// Arrays are pointers continued!
	// Get that type as a pointer, then cast it to a new pointer type, then dereference!
	Entity e = { 5,6 };

	
	int* e_pos = (int*)&e; //this is an array
	int* e_pos_1 = e.get_positions();

	int e_x = *(int*)((char*)e_pos + 4);
	std::cout << e_x << std::endl;

	std::cout << e_pos[0] << " , " << e_pos[1] << std::endl; // thus we index it as an array

	std::cout << "DONE PLAYING NICE!" << std::endl;

	
	std::cout << e.x << " , " << e.y << std::endl;
	
	double& v = *(double*)&e.x;
	v = 162;

	std::cout << e.x << " , " << e.y << std::endl;

	/*
	std::cout << "=========" << std::endl;
	int a = 5;
	std::cout << a << std::endl;
	double b = a;
	uint64_t& c = *(uint64_t*)&a; // now this is a as if a was a double!
	c = 0;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	*/

	std::cin.get();
}