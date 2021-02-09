#include <iostream>


namespace apple {
	void print(const std::string& text) {
		std::cout << text << std::endl;
	}
	namespace funcs {
		void nice_print(const std::string& text) {
			std::cout << " :) "<< text << std::endl;
		}
	}
}

namespace orange {
	void print(const char* text) {
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

using namespace orange;
using namespace apple;


int main() {
	namespace a_man = apple::funcs;

	apple::print("==== using namespace XXX; ====");
	using apple::print;
	print("Chawn");
	a_man::nice_print("Chawn");

	apple::print("==== Using explicit namespacing! ====");
	apple::print("Chawn");
	orange::print("Chawn");
	
	std::cin.get();
}