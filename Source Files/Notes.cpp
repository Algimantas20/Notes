#include <iostream>

#include "Utility/Logger.hpp"

int main()
{
	Logger::ColorPrint("Hello, {World}!", Logger::Color::Red);
}
