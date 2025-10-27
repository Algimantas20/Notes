#include "Note.hpp"

Note::Note(std::string title, std::string content) : m_Title(title), m_Content(content)
{
	m_Created = time(nullptr);
	Logger::ColorPrint("Created:[" + std::to_string(m_Created) + "]", Logger::Color::Magenta);

	m_Id = generate_id();
}

uint64_t Note::generate_id()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();

	return nanos;
}