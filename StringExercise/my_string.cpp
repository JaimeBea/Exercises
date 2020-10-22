#include "my_string.h"

char nullchar = '\0';

size_t string_length(const char* chars)
{
	size_t length = 0;
	while (chars[length] != '\0')
	{
		length += 1;
	}
	return length;
}

String::String() : chars(&nullchar), size(0) {}

String::String(const char* source_chars, size_t length) : chars(new char[length + 1]), size(length)
{
	for (int i = 0; i <= size; ++i)
	{
		chars[i] = source_chars[i];
	}
}

String::String(const char* source_chars) : String(source_chars, string_length(source_chars)) {}

String::String(const String& other) : String(other.chars, other.size) {}

String::String(String&& other) noexcept : chars(other.chars), size(other.size)
{
	other.chars = &nullchar;
	other.size = 0;
}

String::~String()
{
	Clear();
}

String String::operator+(const String& other) const
{
	String result_string;
	size_t result_length = size + other.size;
	result_string.chars = new char[result_length + 1];
	result_string.size = result_length;

	for (int i = 0; i < size; ++i)
	{
		result_string.chars[i] = chars[i];
	}
	for (int i = size; i <= result_length; ++i)
	{
		result_string.chars[i] = other.chars[i - size];
	}

	return result_string;
}

bool String::operator==(const String& other) const
{
	if (size != other.size) return false;

	for (int i = 0; i < size; ++i)
	{
		if (chars[i] != other.chars[i]) return false;
	}

	return true;
}

void String::Clear()
{
	if (chars != &nullchar)
	{
		delete[] chars;
		chars = &nullchar;
	}
	size = 0;
}

size_t String::Length() const
{
	return size;
}

const char* String::GetChars() const
{
	return chars;
}
