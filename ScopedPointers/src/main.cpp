#include <iostream>

class Entity {
public:
	Entity() { std::cout << "Entity Created!" << std::endl; }
	~Entity() { std::cout << "Entity Destroyed!" << std::endl; }
};

class ScopedPtr {
private:
	Entity* m_ep;
public:
	ScopedPtr(Entity* ep) : m_ep(ep) {}
	~ScopedPtr() { delete m_ep; }
};

int main() {
	{
		// Artificial Scoped Pointer
		ScopedPtr sep = new Entity();
		Entity* ep = new Entity();



	}

	std::cin.get();
}