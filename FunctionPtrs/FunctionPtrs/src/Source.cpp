#include <iostream>
#include <vector>
#include <functional>

void PrinterGuy(int val) {
	std::cout << val << std::endl;
}

void HelloWorld() {
	std::cout << "Hello World!" << std::endl;
}

/*
void for_each(const std::vector<int>& values, void(*processor_funk)(int)) {
	for (auto val : values)
		processor_funk(val);
}
*/

void for_each(const std::vector<int>& values, const std::function<void(int)>& processor_funk) {
	for (auto val : values)
		processor_funk(val);
}

int main() {
	void(*funk)() = HelloWorld;
	//auto funk = HelloWorld;
	funk();

	using vector = std::vector<int>;
	vector vals = { 1,3,4,5};
	
	// cool lambda find_if
	auto it = std::find_if(vals.begin(), vals.end(), [](int val) {return val > 3; });
	std::cout << *it <<" , "<< *(it++) << std::endl;

	std::cout << "===== Lambda Below =====" << std::endl;
	int a = 5;
	auto lambda = [=](int val) mutable {a = 7; std::cout << a << "," << val << std::endl; };
	for_each(vals, lambda);

	std::cout << a << std::endl;

	std::cout << "===== Passing Function Ptr Below  =====" << std::endl;
	for_each(vals, PrinterGuy);
	std::cout << "===== Lambda Below =====" << std::endl;
	for_each(vals, [](int val) { std::cout << val << std::endl; });

	std::cin.get();
}