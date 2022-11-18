#pragma once
class Vector2
{
public:
	int x = 0;
	int y = 0;
public:
	Vector2() = default;
	Vector2(const int _x, const int _y);
	Vector2(const Vector2& _copy);
public:
	int X() const;
	int Y() const;
	void Set(const Vector2& _other);
	void Set(const int _newX, const int _newY);
	bool Equal(const Vector2* _other);
#pragma region operator
public:
	Vector2 operator+=(const Vector2& _other);
	Vector2 operator-=(const Vector2& _other);
#pragma endregion operator

};

