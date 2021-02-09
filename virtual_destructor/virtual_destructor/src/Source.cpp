#include <iostream>
#include <string>

class Entity {
public:
	Entity() { std::cout << "Entity Constructor" << std::endl; }
	virtual ~Entity() { std::cout << "Entity Destructor" << std::endl; }
	virtual std::string get_name() { return "Entity"; }
};

class Person : public Entity {
public:
	Person() { m_arr = new int[5]; std::cout << "Person Constructor" << std::endl; }
	~Person() { delete[] m_arr; std::cout << "Person Destructor" << std::endl; }
	std::string get_name() override { return "Chawn"; }
private:
	int* m_arr;
};

void PrintEntity(Entity* ep) {
	std::cout << " Printer " << ep->get_name() << std::endl;
}

int main() {

	Entity* e = new Entity();
	delete e;
	std::cout << "=============\n";
	Person* p = new Person();
	delete p;
	std::cout << "=============\n";
	Entity* ep = new Person();
	delete ep;
	std::cout << "=============\n";

	/*
	Entity* e = new Entity();
	Person* p = new Person();
	std::cout << e->get_name() << std::endl;
	std::cout << p->get_name() << std::endl;
	std::cout << "=============" << std::endl;
	PrintEntity(e);
	PrintEntity(p);
	*/

	std::cin.get();
}