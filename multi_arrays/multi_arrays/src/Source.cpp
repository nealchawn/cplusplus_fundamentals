#include <iostream>
#include <chrono>

struct Timer {
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer() {
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		duration = (end - start) * 1000;

		std::cout << duration.count() << "ms " << std::endl;
	}
};

int main() {
	int* arr = new int[50];

	// each element of a2d points to an array of integers
	int** a2d = new int*[50];
	
	for (int i = 0; i < 50; i++)
		a2d[i] = new int[50];
	
	// each element of a3d points to an array of integer*s to 50 
	/*
	int*** a3d = new int** [50];

	for (int i = 0; i < 50; i++) {
		a3d[i] = new int* [50];
		for (int j = 0; j < 50; j++) {
			a3d[i][j] = new int[50];
		}
	}
	*/

	//cannot delete[] a2d
	for (int i = 0; i < 50; i++)
		delete[] a2d[i];
	delete[] a2d;

	// Avoid multi dimensional arrays; use lin transformations
	// each row requires a jump

	// ex; [5][5] >> [5*5] with a lin trans
	// [(x+y) *width]
	
	{
		Timer timer;
		int** a2d = new int* [5];
		for (int y = 0; y < 5; y++) {
			a2d[y] = new int[5];
			for (int x = 0; x < 5; x++) {
				a2d[y][x] = 2;
			}
		}
	}

	// everytime the y increments jump 5 forward 
	{
		Timer timer;
		int* arr = new int[5*5];
		for (int y=0; y < 5; y++) {
			for (int x=0; x < 5; x++) {
				arr[x + (y * 5)] = 2;
			}
		}
	}
	
	std::cin.get();

	

}