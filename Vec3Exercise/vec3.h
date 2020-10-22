#pragma once

template <class T>
struct Vec3
{
	T x, y, z;

	Vec3() {}

	Vec3(const Vec3<T>& other) : x(other.x), y(other.y), z(other.z) {}

	Vec3(T new_x, T new_y, T new_z) : x(new_x), y(new_y), z(new_z) {}

	Vec3<T> operator+(const Vec3<T>& other) const
	{
		return Vec3(x + other.x, y + other.y, z + other.z);
	}

	Vec3<T> Normalized() const
	{
		float length = Length();

		if (length > -FLT_EPSILON && length < FLT_EPSILON)
		{
			return Vec3(x, y, z);
		}
		
		return Vec3(x / length, y / length, z / length);
	}

	float Length() const const
	{
		return sqrt(x * x + y * y + z * z);
	}

	float DistanceTo(const Vec3<T>& other) const
	{
		float x_diff = other.x - x;
		float y_diff = other.y - y;
		float z_diff = other.z - z;
		return sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
	}

	float DotProduct(const Vec3<T>& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vec3<T> CrossProduct(const Vec3<T>& other) const
	{
		return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	}

	float AngleBetween(const Vec3<T>& other) const
	{
		return acos(DotProduct(other) / (Length() * other.Length()));
	}
};
