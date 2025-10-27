#pragma once
#include "Commands.hpp"
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
#undef max
#undef min

class Logger
{
public:
	enum class Color
	{
		Reset = 0,
		Underline = 4,
		Bold = 1,
		Red = 31,
		Green = 32,
		Yellow = 33,
		Blue = 34,
		Magenta = 35,
		Cyan = 36,
		White = 37
	};
	/*
	* Print text to the console.
	* @param text: The text to print.
	* @return void
	*/
	static void Print(const std::string text);
	/*
	* Print a line of text so the console.
	* @param text: The text to print.
	* @return void
	*/
	static void Println(const std::string text);
	/*
	* Prints text to the console with color formatting.
	* @param text: The text to print, which can include color codes in the format "[color_text]".
	* @param color: The color to apply to the text.
	* @return void
	*/
	static void ColorPrint(const std::string text, Color color, bool new_line = true);
	/*
	 * Displays a menu with options which can be navigated using the arrow keys and
	 * selected with the Enter key.
	 * @param p_OperationTypeNames A mapping of option names to their corresponding
	 *        OperationType values. The keys are displayed in the menu for user selection.
	 * @return void
	 */
	static void DisplaySelectMenu(std::unordered_map<std::string, std::function<void()>> p_OperationTypes);
	/*
	 * Clears the console screen, removing all previously printed output.
	 * @return void
	 */
	static void ClearConsole();
	/*
	* Clears the specified amount of lines in the console, removing all previously printed output.
	* @param line_count: the amount of line to be deleted
	* @return void
	*/
	static void ClearPrevLines(const int line_count);
	/*
	* Get the validated user input from the terminal in the specified type
	* @param text: the outputed text before the input "text: {input}"
	* @return T
	*/
	template<typename T>
	static T& Input(const std::string& text)
	{
		T input;

		while (true)
		{
			Logger::Print(text + ": ");
			std::cin >> input;

			if (!std::cin.fail())
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return input;
			}

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Logger::ClearPrevLines(1);
			Logger::ColorPrint("[Invalid Input.] ", Color::Red, false);
		}
	}
private:
	static constexpr int m_KeyPrefix = 224;
	static constexpr int m_KeyUp = 72;
	static constexpr int m_KeyDown = 80;
	static constexpr int m_KeyEnter = 13;

	static void DrawMenu(std::vector<std::string>& keys, int selected);
};
