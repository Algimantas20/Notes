#include "Utility/Logger.hpp"

void Logger::Print(std::string text)
{
	std::cout << text << std::endl;
}

void Logger::ColorPrint(std::string text, Color color)
{
	int color_code = static_cast<int>(color);

	int brace_start = text.find_first_of("{");
	int brace_end = text.find_first_of("}", brace_start);

	if (brace_start == std::string::npos || brace_end == std::string::npos || brace_start > brace_end)
	{ 
		std::cout << "\033[" << color_code << "m" << text << "\033[0m" << std::endl;
		return;
	}

	std::string before_brace = text.substr(0, brace_start);
	std::string brace_text = text.substr(brace_start + 1, brace_end - brace_start - 1);
	std::string after_brace = text.substr(brace_end + 1);

	std::cout << before_brace << "\033[" << color_code << "m" << brace_text << "\033[0m" << after_brace << std::endl;	
}