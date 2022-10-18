#pragma once

#pragma once
#include <map>
#include <initializer_list>
#include <iostream>
#include "KeyValuePair.h"

template<typename TKey, typename TValue>
class KeyValuePair;

template<typename TKey, typename TValue>


class Map
{
#pragma region f/p
private:
	TValue* tab = nullptr;
	TKey count = 0;
#pragma endregion f/p

#pragma region constructor
public:
	Map() = default;
	Map(std::initializer_list<KeyValuePair<TKey, TValue>> _tab);
	Map(const TKey, TValue _copy);
	~Map();
#pragma endregion constructor

#pragma region method
public:
	void At(const TValue& _item);
	void Clear();
	bool Empty();
	void Insert(TKey* _key);
	void Remove();
	void Contains();
	int Count();
	void Display();
#pragma endregion method
};

	


#pragma region constructor

template<typename TKey, typename TValue>
inline Map<TKey, TValue>::Map(std::initializer_list<KeyValuePair<TKey, TValue>> _tab)
{
	tab = _tab;
}

template<typename TKey, typename TValue>
inline Map<TKey, TValue>::Map(const TKey, TValue _copy)
{
	tab = _copy.tab;
}

template<typename TKey, typename TValue>
inline Map<TKey, TValue>::~Map()
{
	Clear();
}
#pragma endregion constructor

#pragma region method
template<typename TKey, typename TValue>
inline void Map<TKey, TValue>::At(const TValue& _item)
{
	if (_index <0 || _index >count) throw out_of_range("out of range !");
	Node<T>* _head = head;
	for (int i = 0; i < _index && _head->Next(); i++)
	{
		_head = _head->Next();
	}
	return _head->Data();
}

template<typename TKey, typename TValue>
inline void Map<TKey, TValue>::Clear()
{
	if (count <= 1)
		delete tab;
	else
		delete tab;
	count = 0;
}

template<typename TKey, typename TValue>
inline bool Map<TKey, TValue>::Empty()
{
	if (count > 0)
	{
		std::cout << "c'est pas vide" << std::endl;
		return false;
	}
	else
	{
		std::cout << "c'est vide" << std::endl;
		return true;
	}
}

template<typename TKey, typename TValue>
inline void Map<TKey, TValue>::Insert(TKey* _key)
{
	count = _key;
	
}

template<typename TKey, typename TValue>
inline int Map<TKey, TValue>::Count()
{
	return count;
}

template<typename TKey, typename TValue>
inline void Map<TKey, TValue>::Display()
{
}

#pragma endregion method
