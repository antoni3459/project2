#pragma once

template<typename T>
class Case
{
private:
	T data = T();
public:
	Case() = default;
	T Data();
	void SetData(const T& _data);
};

template<typename T>
T Case<T>::Data()
{
	return data;
}

template<typename T>
void Case<T>::SetData(const T&_data)
{
	data = _data;
}

