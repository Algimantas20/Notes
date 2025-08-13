#include "Commands.hpp"

std::unordered_map<std::string, OperationType> g_OperationTypeNames
{
	{"Add", OperationType::Add},
	{"Edit", OperationType::Edit},
	{"Delete", OperationType::Delete},
	{"View", OperationType::View},
	{"List", OperationType::List}
};