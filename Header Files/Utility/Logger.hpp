#pragma once
#include <iostream>
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

	static void Print(std::string text);
	static void ColorPrint(std::string text, Color);
};