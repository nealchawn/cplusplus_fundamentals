#include <iostream>

class Entity {
private:
	int m_x;
public:
	Entity(const int x) : m_x(x) {
	}

	void Print() {
		std::cout << "Hello" << std::endl;
	}

	void Print() const {
		std::cout << "Hello" << std::endl;
	}

	int get_x() const {
		return m_x;
	}
};

struct Vector3 {
	float x, y, z;
};

class ScopedPtr {
private:
	Entity* m_ep;
public:
	ScopedPtr(Entity* ep) : m_ep(ep) {
	}
	~ScopedPtr() {
		delete m_ep;
	}

	Entity* get_obj() {
		return m_ep;
	}

	Entity* operator->() {
		return m_ep;
	}

	const Entity* operator->() const {
		return m_ep;
	}

};

int main() {
	//Entity* ep;
	//int x = ep->get_x();
	//ep->Print();
	//ScopedPtr* sep = new ScopedPtr(ep);
	ScopedPtr e_ptr = new Entity(5);
	const ScopedPtr e_ptr_new = new Entity(5);
	e_ptr.get_obj()->Print();
	// we want overloaded to return ptr
	e_ptr->Print();
	e_ptr_new->Print(); // const

	// offset of member variable
	//((Vector3*)0)->x; ((Vector3*)nullptr)->x;
	int offset = (int)&(((Vector3*)0)->z);
	std::cout << offset << std::endl;

	
	std::cin.get();
}

