#include "Note.hpp"

Note::Note(std::string title, std::string content) : m_Title(title), m_Content(content)
{
	m_Created = time(nullptr);
	m_Id = generate_id();
}

uint64_t Note::generate_id()
{
	auto now = std::chrono::high_resolution_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();

	return static_cast<uint64_t>(nanos);
}

void Note::save_note(const Note& note)
{

}

void to_json(Json& json, const Note& note)
{
	json = Json
	{
		{"Id", note.Id()},
		{"Created_At", note.created_at()},
		{"Title", note.title()},
		{"Content", note.content()}
	};
}

void from_json(Json& json, Note& note)
{
	json.at("id").get_to(note.m_Id);
	json.at("created").get_to(note.m_Created);
	json.at("title").get_to(note.m_Title);
	json.at("content").get_to(note.m_Content);
}