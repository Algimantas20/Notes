#pragma once
#include <unordered_map>
#include <string>
#include <functional>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

extern std::unordered_map<std::string, std::function<void()>> g_OperationTypes;

namespace Commands
{
	static void Add();
	static void Edit();
	static void Delete();
	static void View();
	static void List();
}