#pragma once

template <class T>
struct Vec3
{
	T x, y, z;

	Vec3() : Vec3(0, 0, 0) {}

	Vec3(const Vec3<T>& other) : Vec3(other.x, other.y, other.z) {}

	Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

	inline Vec3<T> operator+(const Vec3<T>& other) const
	{
		return Vec3(x + other.x, y + other.y, z + other.z);
	}

	inline Vec3<T> Normalized() const
	{
		float length = Length();
		return Vec3(x / length, y / length, z / length);
	}

	inline float Length() const const
	{
		return sqrt(x * x + y * y + z * z);
	}

	inline float DistanceTo(const Vec3<T>& other) const
	{
		return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) + (other.z - z) * (other.z - z));
	}

	inline float DotProduct(const Vec3<T>& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	inline Vec3<T> CrossProduct(const Vec3<T>& other) const
	{
		return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	}

	inline float AngleBetween(const Vec3<T>& other) const
	{
		return acos(DotProduct(other) / (Length() * other.Length()));
	}
};
