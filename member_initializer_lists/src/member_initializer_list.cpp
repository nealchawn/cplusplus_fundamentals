#include <iostream>
#define Log(x) std::cout<<"x = "<<x<<std::endl;

class Example {
public:
	Example() {
		Log("nothing");
	}
	Example(int x) {
		Log(x);
	}
};

class Entity {
private:
	std::string m_name;
	Example ex;
public:
	Entity() // this is the member initializer list
	: m_name("Unknown")
	{
		ex = Example(8); // proof of double call
	}
	Entity(std::string name) {
		m_name = name;
	}

	const std::string get_name() const {
		return m_name;
	}
};

static int a = 2;
static int b = 3;

int main() {
	Entity e0;
	//Entity e1("Chawn");

	//std::cout << "Entity 0: " << e0.get_name() << std::endl;
	//std::cout << "Entity 1: " << e1.get_name() << std::endl;

	int result = a > b ? a : b;
	Log(result); // outputs 3

	std::cin.get();
}