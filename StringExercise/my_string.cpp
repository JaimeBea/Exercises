#include "my_string.h"

namespace
{
	// Static string used to avoid allocations when the string is empty
	char nullstring = '\0';

	size_t string_length(const char* chars)
	{
		size_t length = 0;
		while (chars[length] != '\0')
		{
			length += 1;
		}
		return length;
	}
}

String::String() : chars(&nullstring), size(0) {}

String::String(const char* source_chars, size_t length) : chars(new char[length + 1]), size(length)
{
	for (int i = 0; i <= size; ++i)
	{
		chars[i] = source_chars[i];
	}
}

String::String(const char* source_chars) : String(source_chars, string_length(source_chars)) {}

String::String(const String& other) : String(other.chars, other.size) {}

String::String(String&& other) : chars(other.chars), size(other.size)
{
	// Clear the other string without deleting the chars
	other.chars = &nullstring;
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

String& String::operator=(String&& other)
{
	char* temp_chars = chars;
	size_t temp_size = size;
	chars = other.chars;
	size = other.size;
	other.chars = temp_chars;
	other.size = temp_size;
	return *this;
}

void String::Clear()
{
	if (chars != &nullstring)
	{
		delete[] chars;
		chars = &nullstring;
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
