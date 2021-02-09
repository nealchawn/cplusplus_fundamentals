#include <iostream>
#include <string>

#define Log(x) std::cout<<x<<std::endl;

int main() {

	int data[5];
	
	int* ptr = data;

	for (int i = 0; i < 5; i++)
		data[i] = 3;

	data[2] = 6;
	*(ptr + 2) = 7;
	*(int*)((char*)ptr + 8) = 8;

	// heap
	int* another = new int[5];
	for (int i = 0; i < 5; i++)
		*(another + i) = 4;

	char char_arr[6] = {'C','h','a','w','n','\0'}; // 0 instead of \0
	Log(char_arr);

	std::string char_arr2 = "Chawn Again!";
	char_arr2 += " Appended!";

	bool contains = char_arr2.find("Chawn") != std::string::npos;
	Log(contains);
	// or
	std::string char_arr3 = std::string("Chawn's ") + "Back!";


	Log(char_arr2);
	Log(char_arr3);

	delete[] another;

	std::cout << data[2] << std::endl;

	std::cin.get();
}