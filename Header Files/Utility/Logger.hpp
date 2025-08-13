#pragma once
#include <iostream>
#include "Commands.hpp"
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
	static void Print(std::string text);

	/*
	* Prints text to the console with color formatting.
	* @param text: The text to print, which can include color codes in the format "{color_text}".
	* @param color: The color to apply to the text.
	* @return void
	*/
	static void ColorPrint(std::string text, Color);
	/*
	* Displays a menu with options which can be selected by a user
	* @param
	*/
	static void DisplaySelectMenu(std::unordered_map<std::string, OperationType> p_OperationTypeNames);
	/*
	* 
	*/
	static void ClearConsole();
private:
	static constexpr int m_KeyPrefix = 224;
	static constexpr int m_KeyUp = 72;
	static constexpr int m_KeyDown = 80;
	static constexpr int m_KeyEnter = 13;

	static void DrawMenu(std::vector<std::string> &keys, int selected);
};
