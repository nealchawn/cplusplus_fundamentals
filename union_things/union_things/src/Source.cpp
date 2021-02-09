#include <iostream>

struct Vector2 {
	float x, y;
};

// can we see vector4 as 2 vector 2s <x,y> & <z,w>?
struct Vector4 {
	
	// same memory but 2 options for it!
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
	};
	
	/* one option
	Vector2& get_a() {
		return *(Vector2*)&x;
	}
	Vector2& get_b() {
		return *(Vector2*)&z;
	}
	*/
};

void PrintVector2(const Vector2& vec) {
	std::cout << vec.x << " , " << vec.y << std::endl;
}

int main() {
	Vector4 vec = { 1.0f,2.0f,3.0f,4.0f };
	Vector4 vec_2 = { 5.0f,6.0f };

	PrintVector2(vec.a);
	PrintVector2(vec.b);
	PrintVector2(*((Vector2*)&vec+1));
	vec.z = 500.0f;
	PrintVector2(vec.b);



	std::cin.get();
}