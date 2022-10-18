#pragma once
template<typename TKey, typename TValue>
class KeyValuePair
{
#pragma region f/p 
private :
	TKey* key = nullptr;
	TValue* value = nullptr;
	TValue data = nullptr;
#pragma endregion f/p 

#pragma region constructor
public:
	KeyValuePair(TKey _key, TValue _value);
	KeyValuePair(TKey _copyK );
#pragma endregion constructor

#pragma region constructor
public:
	TKey* key(TKey* _key);
	TValue* Value(TValue* _key);
	TValue* Data(TValue* _value);

	TKey* Setkey();
	TValue* SetValue();

#pragma endregion constructor
};

template<typename TKey, typename TValue>
inline KeyValuePair<TKey, TValue>::KeyValuePair(TKey _key, TValue _value)
{
	key = _key;
	value = _value;
}

template<typename TKey, typename TValue>
inline KeyValuePair<TKey, TValue>::KeyValuePair(TKey _copyK)
{
	key = _copyK.key;
	value = _copyK.value;
}

template<typename TKey, typename TValue>
inline TKey* KeyValuePair<TKey, TValue>::Setkey()
{
	return key;
}

template<typename TKey, typename TValue>
inline TValue* KeyValuePair<TKey, TValue>::SetValue()
{
	return value;
}
