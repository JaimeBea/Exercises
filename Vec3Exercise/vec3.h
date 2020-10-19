#pragma once

struct Vec3
{
	Vec3();
	Vec3(const Vec3& other);
	Vec3(float x, float y, float z);

	Vec3 operator+(const Vec3& other) const;

	Vec3 Normalized() const;
	float Length() const;
	float DistanceTo(const Vec3& other) const;
	float DotProduct(const Vec3& other) const;
	Vec3 CrossProduct(const Vec3& other) const;
	float AngleBetween(const Vec3& other) const;

	float x, y, z;
};
