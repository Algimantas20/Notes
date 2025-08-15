#pragma once
#include <string>
#include <time.h>

class Note
{
public:
	Note();
	~Note() = default;
private:
	int m_Id;
	time_t m_created;
	std::string title;
	std::string content;
};