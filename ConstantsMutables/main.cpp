#include <iostream>
#include <string>

class Entity {
private:
	int m_x, *m_y;
	mutable int var;
	// int* m_x, m_y; only m_x would be a pointer
public:
	int get_x() const 
	{ // cannot change the value of m_x
		var = 2; // allows to break const function!
		return m_x;
	}

	// 1st const cannot change y value after returned
	// 2nd const cannot change the point y points to after returned
	// 3rd const will not change m_y inside the method
	const int* const get_y() const {
		return m_y;
	}

	int set_x(int xa) {
		m_x = xa;
	}
};

void PrintEntity(const Entity& e) {
	e.get_x(); // if get_x modifies the entity then const Entity& wont work, unless get_x is const as well;

}

int main() {
	const int MAX_AGE = 90;
	
	int* const a = new int;
	// vs
	const int* b = new int; // or int const * b;

	*a = 5; // cannot change pointer
	b = a; // cannot change value

	auto f = [](int x) {
		std::cout << "Hello from lambda: " << x << std::endl;
	};

	f(6);

	int y = 7;

	auto g = [=]() mutable {
		y++;
		std::cout << "Hello from lambda: " << y << std::endl;
	};
	g();
	// notice y still == 7


	
	//int* a;
	//a = (int*)&MAX_AGE;
	//std::cout <<"a before:" << *a << " address" << a << std::endl;
	//*a += 1;
	//std::cout << "a after:" << *a << " address" << a << std::endl;
	//std::cout << "MAX_AGE:" << MAX_AGE << " address" <<&MAX_AGE << std::endl;

	std::cin.get();
}