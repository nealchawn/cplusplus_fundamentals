#include <iostream>
#include <vector>
#include <thread>

static bool FINISHED = false;

void print_value(int x) {
	std::cout << x << std::endl;
}

void for_each(std::vector<int>& values, void(*func)(int)) {
	for (auto val : values) {
		func(val);
	}
}

void do_work() {
	using namespace std::chrono_literals;

	int i = 0;
	while (!FINISHED) {
		std::cout << i << " working seconds" << std::endl;
		std::this_thread::sleep_for(1s);
		i++;
	}
	
}

int main() {
	std::thread worker(do_work);

	std::cin.get();
	FINISHED = true;
	worker.join();


	std::cout << "==== Done With Thread Work! ====" << std::endl;
	std::vector<int> values = { 1,6,3,2,4,5 };
	for_each(values, print_value);
	std::cout << "=========" << std::endl;

	auto lam = [](int x) {
		std::cout << x << std::endl;
	};
	for_each(values, lam);

	std::cout << "=========" << std::endl;

	for_each(values, [](int x) {
		std::cout << x << std::endl;
	});

	std::cin.get();
}