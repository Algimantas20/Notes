#include "Utility/Logger.hpp"
#include <conio.h>

void Logger::Print(const std::string text)
{
	std::cout << text;
}

void Logger::Println(const std::string text)
{
	std::cout << text << std::endl;
}

void Logger::ColorPrint(const std::string text, Color color, bool new_line)
{
	int color_code = static_cast<int>(color);

	int brace_start = text.find_first_of("[");
	int brace_end = text.find_first_of("]", brace_start);

	std::string new_line_char = (new_line) ? "\n" : "";

	if (brace_start == std::string::npos || brace_end == std::string::npos || brace_start > brace_end)
	{

		std::cout << "\033[" << color_code << "m" << text << "\033[0m" << new_line_char;
		return;
	}

	std::string before_brace = text.substr(0, brace_start);
	std::string brace_text = text.substr(brace_start + 1, brace_end - brace_start - 1);
	std::string after_brace = text.substr(brace_end + 1);

	std::cout << before_brace << "\033[" << color_code << "m" << brace_text << "\033[0m" << after_brace << new_line_char;
}

void Logger::DisplaySelectMenu(std::unordered_map<std::string, std::function<void()>> p_OperationTypes)
{
	bool hasSelected = false;
	int selected = 0;

	std::vector<std::string> keys;
	keys.reserve(p_OperationTypes.size());
	for (const auto& pair : p_OperationTypes)
	{
		keys.push_back(pair.first);
	}

	Logger::DrawMenu(keys, selected);
	while (!hasSelected)
	{
		int input_char = _getch();

		if (input_char == m_KeyPrefix)
		{
			input_char = _getch();
			if (input_char == m_KeyUp)
			{
				selected = (selected - 1 + keys.size()) % keys.size();
				Logger::ClearPrevLines(keys.size());
				Logger::DrawMenu(keys, selected);
			}
			else if (input_char == m_KeyDown)
			{
				selected = (selected + 1) % keys.size();
				Logger::ClearPrevLines(keys.size());
				Logger::DrawMenu(keys, selected);
			}
		}
		else if (input_char == m_KeyEnter)
		{
			hasSelected = true;
			Logger::ClearConsole();

			std::string key = keys[selected];
			g_OperationTypes.at(key)();
		}
	}
}

void Logger::DrawMenu(std::vector<std::string>& keys, int selected)
{
	for (int i = 0; i < keys.size(); ++i)
	{
		if (i == selected)
		{
			Logger::ColorPrint(">" + keys[i], Logger::Color::Cyan);
			continue;
		}

		Logger::Println(" " + keys[i]);
	}
}

void Logger::ClearConsole()
{
	Logger::Print("\033[H\033[2J");
}

void Logger::ClearPrevLines(const int line_count)
{
	Logger::Print("\x1b[" + std::to_string(line_count) + "A");
	for (int i = 0; i < line_count; i++)
	{
		Logger::Print("\x1b[2K");
		Logger::Print("\x1b[1B");
	}
	Logger::Print("\x1b[" + std::to_string(line_count) + "A");
}
