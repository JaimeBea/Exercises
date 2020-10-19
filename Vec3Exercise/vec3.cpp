#include "vec3.h"
#include <cmath>

Vec3::Vec3() : Vec3(0, 0, 0) {}

Vec3::Vec3(const Vec3& other) : Vec3(other.x, other.y, other.z) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& other) const
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::Normalized() const
{
	float length = Length();
	return Vec3(x / length, y / length, z / length);
}

float Vec3::Length() const
{
	return sqrt(x * x + y * y + z * z);
}

float Vec3::DistanceTo(const Vec3& other) const
{
	return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) + (other.z - z) * (other.z - z));
}

float Vec3::DotProduct(const Vec3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::CrossProduct(const Vec3& other) const
{
	return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

float Vec3::AngleBetween(const Vec3& other) const
{
	return acos(DotProduct(other) / (Length() * other.Length()));
}
