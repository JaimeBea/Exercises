#pragma once

class String
{
	char* chars;
	size_t size;

public:
	String();
	String(const char* source_chars, size_t length);
	String(const char* source_chars);
	String(const String& other);
	String(String&& other) noexcept;
	~String();

	String operator+(const String& other) const;
	bool operator==(const String& other) const;

	void Clear();

	size_t Length() const;
	const char* GetChars() const;
};
