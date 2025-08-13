#include "Utility/Logger.hpp"
#include <conio.h>

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

void Logger::ClearConsole()
{
	system("cls");
}

void Logger::DisplaySelectMenu(std::unordered_map<std::string, OperationType> p_OperationTypeNames)
{
	bool hasSelected = false;
	int selected = 0;

	std::vector<std::string> keys;
	keys.reserve(p_OperationTypeNames.size());
	for (const auto& pair : p_OperationTypeNames)
	{
		keys.push_back(pair.first);
	}

	while (!hasSelected)
	{
		Logger::DrawMenu(keys, selected);
		int input_char = _getch();

		if (input_char == m_KeyPrefix)
		{
			input_char = _getch();
			if (input_char == m_KeyUp)
			{
				selected = (selected - 1 + keys.size()) % keys.size();
			}
			else if (input_char == m_KeyDown)
			{
				selected = (selected + 1) % keys.size();
			}
		}
		else if (input_char == m_KeyEnter)
		{
			Logger::ClearConsole();
			Logger::Print(keys[selected]);
			hasSelected = true;
		}
	}
}

void Logger::DrawMenu(std::vector<std::string> &keys, int selected)
{
	Logger::ClearConsole();

	for(int i = 0; i < keys.size(); ++i)
	{
		if (i == selected)
		{
			Logger::ColorPrint(">" + keys[i], Logger::Color::Cyan);
			continue;
		}

		Logger::Print(" " + keys[i]);
	}
}

