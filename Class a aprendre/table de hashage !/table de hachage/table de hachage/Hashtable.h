#pragma once
#include "KeyValue.h"
#include <iostream>
#include <initializer_list>

template<typename TKey, typename TValue>

class Hashtable
{
private:
	TKey key = TKey();
	TValue value = TValue();
	KeyValue< TKey, TValue>* hash = new KeyValue< TKey, TValue>[0];
	int count = 0;

public:
	Hashtable() = default;
	Hashtable(const TKey _key, const TValue _value, const std::initializer_list< KeyValue< TKey, TValue>> _hash);
	Hashtable(const Hashtable< TKey, TValue>& _copy);
	~Hashtable();

private:
	TKey FindOf(const TValue& _value)const;

public:
	void Insert(const KeyValue<TKey, TValue>& _pair);
	void InsertValueKey(const TKey& _key,const TValue& _value);
	bool ContainsValue(const TValue& _value);
	void Clear();
};

template<typename TKey, typename TValue>
inline Hashtable<TKey, TValue>::Hashtable(const TKey _key, const TValue _value, const std::initializer_list<KeyValue<TKey, TValue>> _hash)
{
	key = _key;
	value = _value;
	for (KeyValue<TKey, TValue> Hahs : _hash)
		Insert(Hahs);
}

template<typename TKey, typename TValue>
inline Hashtable<TKey, TValue>::Hashtable(const Hashtable< TKey, TValue>& _copy)
{
	key = _copy.key;
	value = _copy.value;
	hash = _copy.hash;
}

template<typename TKey, typename TValue>
inline Hashtable<TKey, TValue>::~Hashtable()
{
	Clear();
}

template<typename TKey, typename TValue>
inline void Hashtable<TKey, TValue>::Insert(const KeyValue<TKey, TValue>& _pair)
{
	if (ContainsValue(_pair.Value()))
		throw std::exception("value Contains");
	KeyValue<TKey, TValue>* _hash = hash;
	hash = new KeyValue<TKey, TValue>[key + 1];
	for (int i = 0;i < count;i++)
		hash[i] = _hash[i];
	hash[key] = _pair;
	key = key % size_t(hash);
	count++;
}

template<typename TKey, typename TValue>
inline void Hashtable<TKey, TValue>::InsertValueKey(const TKey& _key, const TValue& _value)
{
	Insert(KeyValue<TKey, TValue>(_key, _value));
}

template<typename TKey, typename TValue>
inline bool Hashtable<TKey, TValue>::ContainsValue(const TValue& _value)
{
	if (FindOf(_value) != -1)
	{
		return true;
	}
	else
		return false;
}

template<typename TKey, typename TValue>
inline TKey Hashtable<TKey, TValue>::FindOf(const TValue& _value) const
{
	for (int i = 0; i < count;i++)
	{
		if (hash[i % count] == _value)
			return key = i % count;
	}
	return -1;
}

template<typename TKey, typename TValue>
inline void Hashtable<TKey, TValue>::Clear()
{
	if (count < 1)
		delete hash;
	else
		delete[] hash;

	hash = nullptr;
	key = nullptr;
	value = nullptr;
	count = 0;
}
