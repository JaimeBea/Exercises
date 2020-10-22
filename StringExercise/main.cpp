#include <iostream>
#include "my_string.h"

int main()
{
	String s1 = String();
	std::cout << "Default constructor:\n";
	std::cout << s1.GetChars() << "\n";

	String s2 = String("Hello world");
	std::cout << "Static constructor:\n";
	std::cout << s2.GetChars() << "\n";

	String s3 = String(s2);
	std::cout << "Copy constructor:\n";
	std::cout << s3.GetChars() << "\n";

	String s4 = s2 + s3;
	std::cout << "Concatenation:\n";
	std::cout << s4.GetChars() << "\n";

	bool equals = s2 == s3;
	std::cout << "Equals:\n";
	std::cout << equals << "\n";

	size_t length = s4.Length();
	std::cout << "Length:\n";
	std::cout << length << "\n";

	s2.Clear();
	std::cout << "Clear:\n";
	std::cout << "Cleared\n";

	return 0;
}
