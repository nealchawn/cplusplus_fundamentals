#include <iostream>

class Entity {
public:
	float x, y;

	std::string get_name() {
		return "Entity";
	}

	Entity() {
		std::cout << "Entity Created!" << std::endl;
		x = 0.0f; y = 0.0f;
	}

	Entity(float X, float Y) {
		std::cout << "Entity Created!" << std::endl;
		x = X; y = Y;
	}

	~Entity() {
		std::cout << "Entity Destroyed!" << std::endl;
	}

	void Move(float xa, float ya) {
		x += xa;
		y += ya;
	}

	void Print() {
		std::cout << x << " " << y << std::endl;
	}
};

class Player : public Entity {
public:
	const char* name;
	void PrintName() {
		std::cout << "My Name is: " << name << std::endl;
	}

	Player(const char* some_name) : Entity() {
		name = some_name;
	}

	std::string get_name() {
		return name;
	}
};

void caller_function() {
	//Player e(5.0f, 10.0f);
	Player e("Chawn");

	/* V-tables, Virtual Functions and overrides */



	e.x = 5.5f;
	e.Print();
	e.PrintName();
}

int main() {
	caller_function();
	std::cin.get();
}