#include <iostream>
#include <memory>

#define Log(x) std::cout<<x<<std::endl;

struct Entity {
	Entity() { Log("Entity Created!"); }
	~Entity() { Log("Entity Destroyed!"); }
};

int main() {
	std::weak_ptr<Entity> wp;
	{
		std::shared_ptr<Entity> sp;
		{
			// Unique cannot be shared and die after they leave the scope, Exception handling
			std::unique_ptr<Entity> up = std::make_unique<Entity>();

			// Shared pointers die after all of their references die out
			// Currently only has 2 sp and sp2; 
			// weak_ptr does not make a reference and thus dies with the shared pointer
			std::shared_ptr<Entity> sp2 = std::make_shared<Entity>();
			wp = sp2;
			sp = sp2;
		}
	}

	std::cin.get();
}