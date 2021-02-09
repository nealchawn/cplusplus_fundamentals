#include <iostream>
#include <string>

using String = std::string;


class Entity {
private:
	String m_name;
	int m_age;
public:
	Entity() : m_name("Unknown"), m_age(24){}
	explicit Entity(const String& name) : m_name(name), m_age(24) {}
	Entity(int age) : m_name("Chawn Def"), m_age(age) { }
	const String const get_name() const { return m_name; }
};

void PrintEntity(const Entity& e){}

int main() {
	Entity e0("Chawn_0");
	Entity e1 = Entity("Chawn_1");
	
	Entity e3 = 24; // Implicit
	PrintEntity(24); //Implicitly convert to Entity(24)

	// the above both valid and both the same >> stack
	Entity* ep;
	{
		Entity* eh = new Entity(); // created on the heap
		ep = eh;
		// with new keyword it returns reference to memory location
		// java always writes to the heap >> c# too.. sorta
		delete eh; // cleanup free memory
	}

	//or 
	delete ep; //if we didnt have delete eh

	Entity* f = new Entity();
	// or same as 
	//Entity* f = (Entity*)malloc(sizeof(Entity));
	
	// the only difference is new will call the constructor
	// in c++ don't use malloc
	
	delete f;
	// same as free analogous to malloc
	// delete analogously calls the deconstructor
	//free(f);


	std::cin.get();
}