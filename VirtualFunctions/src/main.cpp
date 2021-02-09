#include <iostream>
class Printable {
public:
	// pur virtual / Abstract / Interface
	virtual std::string get_class_name() =  0;
};

class Entity : Printable {
public:
	virtual std::string get_name() { return "Entity"; }

	std::string get_class_name() override { return "Entity"; }
};


class Person : public Entity// , Printable 
{
private:
	std::string m_name;
public:
	Person(const std::string& name) : m_name(name){}

	std::string get_class_name() { return "Person"; }

	std::string get_name() override { return m_name;  }
};

void PrintName(Entity* e) {
	// this is why we need v-table and override
	std::cout << e->get_name() << std::endl;
}

int main() {
	Entity* e = new Entity();
	std::cout << e->get_name() << std::endl;

	Person* p = new Person("Chawn");
	std::cout << p->get_name() << std::endl;

	Entity* x = p;
	std::cout << x->get_name() << std::endl;
	
	std::cout << "====================" << std::endl;

	PrintName(e);
	PrintName(p);

	std::cout << "====================" << std::endl;

	std::cout << e->get_class_name() << std::endl;
	std::cout << p->get_class_name() << std::endl;

	std::cin.get();
}