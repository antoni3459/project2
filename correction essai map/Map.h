#pragma once
#include "KeyValuePair.h"
#include <vector>
#include <initializer_list>
#include <exception>




template<typename TKey, typename TValue>

class Map
{
#pragma region f/P

private:
	KeyValuePair<TKey, TValue>* tab = new KeyValuePair<TKey, TValue>[0];
	int count = 0;
#pragma region f/p

#pragma region Typedef
public:
	typedef KeyValuePair<TKey, TValue>* iterator;
	typedef const KeyValuePair<TKey, TValue>* const_iterator;
	iterator begin()
	{
		return &tab[0];
	}
	const_iterator begin() const
	{
		return &tab[0];
	}
	iterator end()
	{
		return &tab[count];
	}
	const_iterator end() const
	{
		return &tab[count];
	}
#pragma endregion Typedef

#pragma region Typedef
#pragma endregion constructor


public:
	Map() = default;
	Map(std::initializer_list< KeyValuePair<TKey, TValue>> _tab);
	Map(const Map& _copy);
	~Map();

#pragma region constructor
#pragma endregion constructor


#pragma region method
private:
	int IndexOfKey(const TKey& _key)const;
public:
	void Insert(const TKey& _key, const TValue& _value);
	void Insert(const KeyValuePair<TKey, TValue>& _pair);
	TValue& At(const TKey& _key);
	void Clear();
	bool IsEmpty()const;
	void Remove(const TKey& _key);
	bool Contains(const TKey& _key);
#pragma endregion method
#pragma region operator
	TValue& operator[](const TKey& _key);
#pragma endregion operator
};


#pragma region f/P
template<typename TKey, typename TValue>
Map<TKey, TValue>::Map(std::initializer_list<KeyValuePair<TKey, TValue>> _tab)
{
	for (KeyValuePair<TKey, TValue> _pair : _tab)
		Insert(_pair);
}

template<typename TKey, typename TValue>
Map<TKey, TValue>::Map(const Map& _copy)
{
	tab = _copy.tab;
}

template<typename TKey, typename TValue>
Map<TKey, TValue>::~Map()
{
	delete[] tab;
	count = 0;
	tab = nullptr;
}
#pragma region Typedef


#pragma region constructor


template<typename TKey, typename TValue>
int Map<TKey, TValue>::IndexOfKey(const TKey& _key) const
{
	for (size_t i = 0; i < count; i++)
	{
		if (tab[i].Key() == _key)
			return i;
	}
	return -1;
}

template<typename TKey, typename TValue>
void Map<TKey, TValue>::Insert(const TKey& _key, const TValue& _value)
{
	Insert(KeyValuePair<TKey, TValue>(_key, _value));
}

template<typename TKey, typename TValue>
void Map<TKey, TValue>::Insert(const KeyValuePair<TKey, TValue>& _pair)
{
	if (Contains(_pair.Key()))
		throw std::exception("key already exist");
	KeyValuePair<TKey, TValue>* _tmp = tab;
	tab = new KeyValuePair<TKey, TValue>[count + 1];
	for (int i = 0; i < count; i++)
		tab[i] = _tmp[i];
	tab[count] = _pair;
	count++;
}

template<typename TKey, typename TValue>
TValue& Map<TKey, TValue>::At(const TKey& _key)
{
	const int _index = IndexOfKey(_key);
	if (_index == -1) throw std::exception("key doesn't exist !");
	return tab[_index].Value();
}

template<typename TKey, typename TValue>
void Map<TKey, TValue>::Clear()
{

	delete[] tab;
	count = 0;
	tab = new KeyValuePair<TKey, TValue>[0];
}

template<typename TKey, typename TValue>
bool Map<TKey, TValue>::IsEmpty() const
{
	return tab.size() == 0;;
}

template<typename TKey, typename TValue>
void Map<TKey, TValue>::Remove(const TKey& _key)
{
	const int _index = IndexOfKey(_key);
	if (_index == -1) throw std::exception("key doesn't exist");
	KeyValuePair<TKey, TValue>* _tmp = tab;
	tab = new KeyValuePair<TKey, TValue>[count - 1];
	for (int i = 0; i < _index; i++)
		tab[i] = _tmp[i];
	for (int i = _index + 1; i < count; i++)
		tab[i - 1] = _tmp[i];
	count--;
}

template<typename TKey, typename TValue>
bool Map<TKey, TValue>::Contains(const TKey& _key)
{
	return IndexOfKey(_key) != -1;
}
#pragma region constructor
#pragma endregion constructor

#pragma endregion constructor
 template<typename TKey, typename TValue>
  TValue& Map<TKey, TValue>::operator[](const TKey& _key)
 {
	 return At(_key);
 }
