#include <iostream>
#include <chrono>
#include <thread>

#define LOG(x) std::cout<<x<<std::endl;

struct Timer {
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer() {
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		duration = (end - start)*1000;

		std::cout << duration.count() << "ms " << std::endl;
	}
};

void test_function_1() {
	Timer timer;

	for (int i = 0; i < 100; i++)
		std::cout << "Hello";
}

void test_function_2() {
	Timer timer;

	for (int i = 1; i <= 100; i++)
		std::cout << "Hello";
}

int main() {
	using namespace std::chrono_literals;
	
	// platform independent
	/*
	auto start = std::chrono::high_resolution_clock::now(); // current time
	std::this_thread::sleep_for(1s);
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;
	std::cout << duration.count() << "s " << std::endl;
	*/

	LOG("scope 1");
	{
		Timer timer = Timer();
		std::this_thread::sleep_for(1s);
	}
	LOG("scope 2");
	test_function_1();
	LOG("scope 3");
	test_function_2();

	std::cin.get();
}