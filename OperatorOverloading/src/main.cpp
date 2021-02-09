#include <iostream>
#include <string>

struct Vector2 {
	float m_x, m_y;

	Vector2() : m_x(0), m_y(0){}
	Vector2(float x, float y) : m_x(x), m_y(y){}

	const Vector2 Add(const Vector2& v2) const {
		return (Vector2(m_x+v2.m_x, m_y + v2.m_y));
	}

	const Vector2 operator+(const Vector2& v2) const {
		return Add(v2);
	}

	bool operator==(const Vector2& v2) const {
		return ((m_x == v2.m_x) && (m_y == v2.m_y));
	}

	bool operator!=(const Vector2& v2) const {
		// alternatively return !(operator==(v2));
		return !(*this==v2);
	}

};

std::ostream& operator<<(std::ostream& stream, const Vector2& v) {
	stream << v.m_x << " , " << v.m_y;
	return stream;
}

int main() {

	Vector2 v_position(5.0, 6.0);
	Vector2 v_position_new(5.0, 6.0);
	Vector2 v_delta_postion(1.0, 2.0);
	//Vector2 v_current_position;

	std::cout << ((v_position == v_position_new) ? "True" : "False") << std::endl;

	v_position = v_position.Add(v_delta_postion);
	v_position = v_position + v_delta_postion; // + operator overloaded
	v_position = v_position.operator+(v_delta_postion); // valid way to call

	std::cout << v_position << std::endl;
	std::cout << ((v_position != v_position_new) ? "True" : "False") << std::endl;
	//std::cout << "x: " << v_position.m_x << " y: " << v_position.m_y << std::endl;

	std::cin.get();
}