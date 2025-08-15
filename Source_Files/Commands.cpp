#include "Commands.hpp"
#include "Utility/Logger.hpp"



std::unordered_map<std::string, std::function<void()>> g_OperationTypes
{
	{"Add",    []() { Commands::Add(); }},
	{"Edit",   []() { Commands::Edit(); }},
	{"Delete", []() { Commands::Delete(); }},
	{"View",   []() { Commands::View(); }},
	{"List",   []() { Commands::List(); }},
};

void Commands::Add()
{
	auto input = Logger::Input<std::string>("Input the notes title");
	Logger::Println(input);
}

void Commands::Edit()
{
	Logger::Print("Editing");
}

void Commands::Delete()
{
	Logger::Print("Deleting");
}

void Commands::List()
{
	Logger::Print("Listing");
}

void Commands::View()
{
	Logger::Print("Viewing");
}