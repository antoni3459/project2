#pragma once
template<typename TKey, typename TValue>

class KeyValuePair
{
#pragma region f/p
private:
	TKey key = TKey();
	TValue value = TValue();
#pragma endregion f/p

#pragma region f/p
public:
	KeyValuePair() = default;
	KeyValuePair(const TKey _key, const TValue _value);
	KeyValuePair(const KeyValuePair& _copy);

	TKey Key() const;
	TValue& Value();

#pragma endregion f/p

};

template<typename TKey, typename TValue>
inline KeyValuePair<TKey, TValue>::KeyValuePair(const TKey _key, const TValue _value)
{
	value = _value;
	key = _key;
}

template<typename TKey, typename TValue>
inline KeyValuePair<TKey, TValue>::KeyValuePair(const KeyValuePair& _copy)
{
	key = _copy.key;
	value = _copy.value;
}

template<typename TKey, typename TValue>
inline TKey KeyValuePair<TKey, TValue>::Key() const
{
	return key;
}

template<typename TKey, typename TValue>
 TValue& KeyValuePair<TKey, TValue>::Value() 
{
	return value;
}
