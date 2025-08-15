#include <iostream>
#include <Windows.h>
#include <Utility/Logger.hpp>

static void enable_ansi()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE) return;

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode)) return;

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
}

int main()
{
	enable_ansi();
	Logger::Println("Notes");
	Logger::DisplaySelectMenu(g_OperationTypes);
}
