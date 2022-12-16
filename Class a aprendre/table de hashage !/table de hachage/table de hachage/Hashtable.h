#pragma once
#include "KeyValue.h"
#include <iostream>
#include <initializer_list>

template<typename TKey, typename TValue>

class Hashtable
{
#pragma region f/p
private
	KeyValue< TKey, TValue>* hash = new KeyValue< TKey, TValue>[0];
	int count = 0;
	short key = 0;

#pragma endregion f/p

#pragma region Typedef

public:
	typedef KeyValue<TKey, TValue>* iterator;
	typedef const KeyValue<TKey, TValue>* const_iterator;
	iterator begin()
	{
		return &hash[0];
	}
	const_iterator begin() const
	{
		return &hash[0];
	}
	iterator end()
	{
		return &hash[count];
	}
	const_iterator end() const
	{
		return &hash[count];
	}

#pragma endregion Typedef

#pragma region constructor

public:
	Hashtable() = default;
	Hashtable(const std::initializer_list< KeyValue< TKey, TValue>> _hash);
	Hashtable(const Hashtable< TKey, TValue>& _copy);
	~Hashtable();

#pragma endregion constructor

#pragma region method

private:
	short FindOf(const TKey& _key)const;

public:
	void Insert(const KeyValue<TKey, TValue>& _pair);
	void InsertValueKey(const TKey& _key, const TValue& _value);
	TValue& At(const TKey& _key);
	bool Contains(const TKey& _key);
	void Hash();
	void Clear();
	void Display();

#pragma endregion method

#pragma region operrator

public:
	TValue& operator[](const TKey& _key);

#pragma endregion operrator

};

#pragma region constructor

template<typename TKey, typename TValue>
inline Hashtable<TKey, TValue>::Hashtable(const std::initializer_list< KeyValue< TKey, TValue>> _hash)
{
	for (KeyValue<TKey, TValue> _pair : _hash)
		Insert(_pair);
}

template<typename TKey, typename TValue>
inline Hashtable<TKey, TValue>::Hashtable(const Hashtable< TKey, TValue>& _copy)
{
	hash = _copy.hash;
}

template<typename TKey, typename TValue>
inline Hashtable<TKey, TValue>::~Hashtable()
{
	Clear();
}

#pragma endregion constructor

#pragma region method

template<typename TKey, typename TValue>
short Hashtable<TKey, TValue>::FindOf(const TKey& _key) const
{
	for (size_t i = 0; i < count; i++)
	{
		if (hash[i].Key() == _key)
			return i;
	}
	return -1;
}

template<typename TKey, typename TValue>
inline void Hashtable<TKey, TValue>::Insert(const KeyValue<TKey, TValue>& _pair)
{
	if (Contains(_pair.Key()))
		throw std::exception("key already exist");
	KeyValue<TKey, TValue>* _hash = hash;
	hash = new KeyValue<TKey, TValue>[count + 1];
	for (int i = 0; i < count; i++)
		hash[i] = _hash[i];
	hash[count] = _pair;
	count++;
}

template<typename TKey, typename TValue>
inline void Hashtable<TKey, TValue>::InsertValueKey(const TKey& _key, const TValue& _value)
{
	Insert(KeyValue<TKey, TValue>(_key, _value));

}

template <typename TKey, typename TValue>
TValue& Hashtable<TKey, TValue>::At(const TKey& _key)
{
	const int _index = FindOf(_key);
	if (_index == -1) throw std::exception("key doesn't exist !");
	return hash[_index].Value();
}

template<typename TKey, typename TValue>
inline bool Hashtable<TKey, TValue>::Contains(const TKey& _key)
{
	return FindOf(_key) != -1;

}

template<typename TKey, typename TValue>
void Hashtable<TKey, TValue>::Hash()
{
	std::cout << "key = (_key/10)% count" << std::endl;
}

template<typename TKey, typename TValue>
inline void Hashtable<TKey, TValue>::Clear()
{
	if (count < 1)
		delete hash;
	else
		delete[] hash;

	hash = nullptr;
	count = 0;
}

template<typename TKey, typename TValue>
inline void Hashtable<TKey, TValue>::Display()
{
	std::cout << hash->Value() << std::endl;
}

#pragma endregion method

#pragma region operrator

template<typename TKey, typename TValue>
TValue& Hashtable<TKey, TValue>::operator[](const TKey& _key)
{
	return At(_key);
}

#pragma endregion operrator

