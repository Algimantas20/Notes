#pragma once
#include <Utility/Logger.hpp>
#include <Utility/json.hpp>
#include <string>
#include <random>
#include <chrono>
#include <ctime>

using Json = nlohmann::json;

class Note
{
public:
	Note(std::string title, std::string content);
	~Note() = default;

	inline int Id() const { return m_Id; }
	inline std::time_t created_at() const { return m_Created; }
	inline std::string title() const { return m_Title; }
	inline std::string content() const { return m_Content; }

	static void save_note(const Note& note);
private:
	uint64_t m_Id;
	std::time_t m_Created;
	std::string m_Title;
	std::string m_Content;

	static uint64_t generate_id();

	friend void to_json(Json& json, const Note& note);
	friend void from_json(Json& json, Note& note);
};