#pragma once

template<typename TKey, typename TValue>
class KeyValue
{
#pragma region f/p

private:
	TKey key = TKey();
	TValue value = TValue();

#pragma endregion f/p

#pragma region constructor/destructor

public:
	KeyValue() = default;
	KeyValue(const TKey _key, const TValue _value);
	KeyValue(const KeyValue& _copy);

#pragma endregion constructor/destructor

#pragma region method 

public:
	TKey Key();
	TValue Value();

#pragma endregion method 

};
#pragma region constructor

template<typename TKey, typename TValue>
inline KeyValue<TKey, TValue>::KeyValue(const TKey _key, const TValue _value)
{
	key = _key;
	value = _value;
}

template<typename TKey, typename TValue>
inline KeyValue<TKey, TValue>::KeyValue(const KeyValue& _copy)
{
	key = _copy.key;
	value = _copy.value;
}

#pragma endregion constructor

#pragma region method

template<typename TKey, typename TValue>
inline TKey KeyValue<TKey, TValue>::Key()
{
	key = key % 10;
	return key;
}

template<typename TKey, typename TValue>
inline TValue KeyValue<TKey, TValue>::Value()
{
	return value;
}

#pragma endregion method
