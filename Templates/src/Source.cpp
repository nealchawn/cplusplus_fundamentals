#include <iostream>
#include <string>

// #include <array>



#ifdef PR_DEBUG
#define LOG(x) std::cout<<x<<std::endl
#define NICE_LOG(x) \
std::cout<<" :) "<<x<<std::endl 
#else
#define LOG(x)
#define NICE_LOG(x)
#endif

// Aliasing
using Stringy = std::string;
typedef std::string Stringy2;

struct SomeStruct {
	int x;
	int y;
	SomeStruct() : x(5), y(6) {

	}
};

template<typename X,int N>
class Array {
private:
	X m_array[N];
	//int m_size;
public:
	int get_size() const { return N; }
};

// Overloads output operator so we can pass as template to PrintGuy
std::ostream& operator<<(std::ostream& stream,const SomeStruct s) {
	stream << s.x << " , " << s.y;
	return stream;
}

template<typename T>

void PrintGuy(T value) {
	std::cout << value << std::endl;
}

int main() {
	// Meta Programming Programming the compiler instead of Runtime
	SomeStruct s;
	
	// std::array<int, 5> test_arr;
	// test_arr.size()

	Array<std::string, 5> arr; // Creates a string array of size 5
	Array<int, 6> arr_2; // Creates an int array of size 6

	PrintGuy("Some String");
	PrintGuy<float>(5.5f);
	PrintGuy(s);

	NICE_LOG("Hello Debugging!");

	// Auto & Typdef & Using
	Stringy first_string = "This is using Stringy!";
	Stringy2 second_string = "This is a typdef Stringy2!";
	auto third_string = (Stringy)"This is a auto String";

	std::cout << first_string << second_string << third_string << std::endl;



	std::cin.get();
}