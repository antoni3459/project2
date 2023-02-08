#pragma once
#include <initializer_list>

class List
{
private:
	static inline int* liste = nullptr;
	static inline int count = 0;

public:
	List() = default;
	List(const std::initializer_list<int> _list);
	List(const List& _copy);
	~List();
public:
	static void Add(int _x);
	static bool Contains(int& _x);
};

