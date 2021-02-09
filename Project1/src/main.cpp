#include <iostream>
class Log {
public:
	enum Level {
		level_error = 0, level_warn, level_info
	};
	//const int level_error = 0;
	//const int level_warn = 1;
	//const int level_info = 2;
private:
	Level m_log_level = level_info;
public:
	void SetLevel(Level level) {
		m_log_level = level;
	}

	void warn(const char* message) {
		if (m_log_level >= level_warn) {
			std::cout << "[WARN]: " << message << std::endl;
		}
	}

	void error(const char* message) {
		if (m_log_level >= level_error) {
			std::cout << "[ERROR]: " << message << std::endl;
		}
	}

	void info(const char* message) {
		if (m_log_level >= level_info) {
			std::cout << "[INFO]: " << message << std::endl;
		}
	}
};

int main() {
	Log logger;

	logger.SetLevel(logger.level_info);
	logger.warn("Hello!");
	logger.error("Hello!");
	logger.info("Hello!");

	std::cin.get();
}