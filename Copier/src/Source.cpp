#include <iostream>
#include <string>

class String {
private:
	char* m_buffer;
	unsigned int m_size;
public:
	String(const char* string) {
		m_size = strlen(string);

		m_buffer = new char[m_size+1];
		memcpy(m_buffer, string, m_size);
		m_buffer[m_size] = 0;

	}

	String(const String& other)
		// : m_buffer(other.m_buffer), m_size(other.m_size) what default copy does
		: m_size(other.m_size)
	{
		// deep copy
		m_buffer = new char[m_size+1]; // create a pointer
		memcpy(m_buffer, other.m_buffer, m_size +1); // copy other string into this new string location
		// memcpy(this, &other, sizeof(String));
		std::cout << "Deep copy created" << std::endl;
	}

	// String(const String& other) = delete; remove copy functionality >> unique_ptr

	~String() {
		delete[] m_buffer;
	}

	char& operator[](unsigned int index) {
		return m_buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	
	stream << string.m_buffer;
	return stream;
}

// if we dont pass by reference this creates a new string that will ultimately be destroyed
void PrintString(const String& string) {
	std::cout << string << std::endl;
}

int main() {
	
	// This causes error because on destruction the two shallow copies reference the same pointer.
	String string = "Chawn"; // Implicit
	String string_2 = string;

	string_2[2] = 'e';


	PrintString(string);
	PrintString(string_2);
	//std::cout << string << std::endl;
	//std::cout << string_2 << std::endl;
	
	std::cin.get();
}