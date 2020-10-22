#include <iostream>
#include "vec3.h"

int main()
{
	Vec3<float> v1 = Vec3<float>();
	std::cout << "Default constructor:\n";
	std::cout << "(" << v1.x << ", " << v1.y << ", " << v1.z << ")\n";

	Vec3<float> v2 = Vec3<float>(1, 2, 3);
	std::cout << "Non-default constructor:\n";
	std::cout << "(" << v2.x << ", " << v2.y << ", " << v2.z << ")\n";

	Vec3<float> v3 = Vec3<float>(v2);
	std::cout << "Copy:\n";
	std::cout << "(" << v3.x << ", " << v3.y << ", " << v3.z << ")\n";

	Vec3<float> v4 = v2 + Vec3<float>(4, 3, 2);
	std::cout << "Addition:\n";
	std::cout << "(" << v4.x << ", " << v4.y << ", " << v4.z << ")\n";

	Vec3<float> v5 = v2.Normalized();
	std::cout << "Normalization:\n";
	std::cout << "(" << v5.x << ", " << v5.y << ", " << v5.z << ")\n";

	float length = v2.Length();
	std::cout << "Length:\n";
	std::cout << "(" << length << ")\n";

	float distance = v2.DistanceTo(v4);
	std::cout << "Distance:\n";
	std::cout << "(" << distance << ")\n";

	float dot = v2.DotProduct(v4);
	std::cout << "Dot product:\n";
	std::cout << "(" << dot << ")\n";

	Vec3<float> v6 = v2.CrossProduct(v4);
	std::cout << "Cross product:\n";
	std::cout << "(" << v6.x << ", " << v6.y << ", " << v6.z << ")\n";

	float angle = v2.AngleBetween(v4);
	std::cout << "Angle:\n";
	std::cout << "(" << angle << ")\n";

	return 0;
}
