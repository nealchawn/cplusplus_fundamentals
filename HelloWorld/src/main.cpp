#include <iostream>
#include "Log.h"

#define NEW_LOG(x) Log(x)
#define Player PlayerStruct

//void Log(const char*);

class PlayerClass {
public:
	int x=0, y=0;
	int speed=0;

	void Move(int xa, int ya) {
		x += xa * speed;
		y += ya * speed;
	}
};

struct PlayerStruct {
// private >> default public
	int x = 0, y = 0;
	int speed = 0;

	void Move(int xa, int ya) {
		x += xa * speed;
		y += ya * speed;
	}
};

void MovePlayer(Player& player, int xa, int ya) {
	player.x += xa * player.speed;
	player.y += ya * player.speed;
}

void static_var() {
	static int var = 0;
	var++;
	std::cout << "Hello: " << var << std::endl;
}


int main() {
	NEW_LOG("Hello World!");
	Player player;

	MovePlayer(player, 3, 4);
	player.Move(2, -2);

	static_var();
	static_var();
	static_var();

	std::cin.get();
}