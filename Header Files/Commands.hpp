#pragma once
#include <unordered_map>
#include <string>
#include <functional>

enum class OperationType
{
	Add = 1,
	Edit,
	Delete,
	View,
	List
};

extern std::unordered_map<std::string, OperationType> g_OperationTypeNames;
extern std::unordered_map<OperationType, std::function<void()>> g_OperationTypes;

