#pragma once

template<typename TKey, typename TValue>
class KeyValue
{
private:
	TKey key = TKey();
	TValue value = TValue();
	
public:
	KeyValue() = default;
	KeyValue(const TKey _key, const TValue _value);
	KeyValue(const KeyValue& _copy);

public:
	TKey Key();
	TValue Value();
};

template<typename TKey, typename TValue>
inline KeyValue<TKey, TValue>::KeyValue(const TKey _key, const TValue _value)
{
	key=_key;
	value = _value;
}

template<typename TKey, typename TValue>
inline KeyValue<TKey, TValue>::KeyValue(const KeyValue& _copy)
{
	key=_copy.key;
	value = _copy.value;
}

template<typename TKey, typename TValue>
inline TKey KeyValue<TKey, TValue>::Key()
{
	return key;
}

template<typename TKey, typename TValue>
inline TValue KeyValue<TKey, TValue>::Value() 
{
	return value;
}
