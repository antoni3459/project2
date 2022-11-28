#pragma once
namespace Core
{
	enum class BindingFlags :int
	{
		Public = 1,
		Private = 2,
		Static = 4,
		Const = 8
	};

	O3DLIBRAIRY_API inline BindingFlags operator | (BindingFlags _lhs, BindingFlags _rhs)
	{
		return BindingFlags((int)_lhs | (int)_rhs);
	}

	O3DLIBRAIRY_API inline bool operator&(BindingFlags _lhs, int _rhs)
	{
		return (int)_lhs & _rhs;
	}

	O3DLIBRAIRY_API inline bool operator&(BindingFlags _lhs, BindingFlags _rhs)
	{
		return (int)_lhs & (int)_rhs;
	}
}