#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	std::vector<int> values = { 3,1,2,5,6 };

	std::sort(values.begin(), values.end());
	for (int val : values)
		std::cout << val << "," << std::endl;

	std::cout << "============"<<std::endl;

	std::sort(values.begin(), values.end(), std::greater<int>());
	for (int val : values)
		std::cout << val << "," << std::endl;

	std::cout << "============" << std::endl;

	/*
	comparison returns bool
	if we give it 2 vals a & b, which should appear first in a list?
	return true then  a before b
	return false then b before a
	*/
	std::sort(values.begin(), values.end(), [](int a, int b) {
		if (b == 1)
			return true; // send a to the back & b to front >> 
		else
			false;
		//	return a > b; // if a less than be then sort to the front of the list
	});

	for (int val : values)
		std::cout << val << "," << std::endl;

	std::cin.get();
}