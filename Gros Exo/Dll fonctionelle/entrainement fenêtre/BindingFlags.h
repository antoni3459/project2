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

	inline BindingFlags operator | (BindingFlags _lhs, BindingFlags _rhs)
	{
		return BindingFlags((int)_lhs | (int)_rhs);
	}

	inline bool operator&(BindingFlags _lhs, int _rhs)
	{
		return (int)_lhs & _rhs;
	}

	inline bool operator&(BindingFlags _lhs, BindingFlags _rhs)
	{
		return (int)_lhs & (int)_rhs;
	}
}