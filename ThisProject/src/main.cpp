#include <iostream>
#include <string>

void PrintEntity(const Entity* ep);
void PrintEntityAgain(const Entity& e);

class Entity {
public:
	int x, y;
	Entity(int x, int y) {
		// Entity* ep = this; 
		this->x = x;
		this->y = y;

		// Entity ep = *this;

		PrintEntity(this);
		PrintEntityAgain(*this);
	}

	int get_x() const {
		const Entity* ep = this;
		return ep->x;
	}
};

void PrintEntity(const Entity* ep) {
}

void PrintEntityAgain(const Entity& e) {
}