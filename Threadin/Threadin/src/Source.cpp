#include <iostream>
#include <thread>

#define LOG(x) std::cout<<x<<std::endl;

bool FINISHED_WORKING = false;


void do_work() {
	using namespace std::chrono_literals;
	std::cout << "Working Thread=" << std::this_thread::get_id() << std::endl;
	while (!FINISHED_WORKING) {
		LOG("Working in thread!");
		std::this_thread::sleep_for(1s);
	}
}

int main() {

	std::thread worker(do_work);
	LOG("In Main Thread!");
	std::cin.get();
	FINISHED_WORKING = true;
	std::cout << "Main Thread=" << std::this_thread::get_id() << std::endl;

	worker.join();
	std::cout << "Finished Working Main thread!" << std::endl;

	std::cin.get();
}