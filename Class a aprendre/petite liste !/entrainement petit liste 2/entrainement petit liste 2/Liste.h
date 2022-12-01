#pragma once
#include <initializer_list>
#include <exception>
#include <iostream>

template<typename T>
class Liste
{
private:
	T* list = nullptr;
	int count = 0;
public:
	Liste() = default;
	Liste(const std::initializer_list<T> _list);
	Liste(const Liste& _copy);
	~Liste();

private:
	int FindOf(const T _index);
public:
	void Add( T _item);
	void Remove( T _item);
	void RemoveAt(const int& _index);
	void RemoveAll(T& _item);
	bool Contains(const T& _item);
	int Count();
	void Clear();
	void Display();
};

template<typename T>
inline Liste<T>::Liste(const std::initializer_list<T> _list)
{
	count = _list.size();
	list = new T[count];
	int _index = 0;
	for (T _iteme : _list)
		list[_index++] = _iteme;
}

template<typename T>
inline Liste<T>::Liste(const Liste& _copy)
{
	list = _copy.list;
}

template<typename T>
inline Liste<T>::~Liste()
{
	Clear();
}

template<typename T>
inline int Liste<T>::FindOf(const T _item)
{
	for (int i = 0; i < count; i++)
		if (list[i] == _item)
			return i;
	return -1;
}

template<typename T>
inline void Liste<T>::Add(T _item)
{
	T* _liste = list;
	list = new T[count+1];
	for (int i = 0; i < count; i++)
		list[i] = _liste[i];
	list[count] = _item;
	count++;
}

template<typename T>
inline void Liste<T>::Remove( T _item)
{
	const int _index = FindOf(_item);
	if (_index == -1) throw std::exception("out of range");
	RemoveAt(_index);
}

template<typename T>
inline void Liste<T>::RemoveAt(const int& _index)
{
	T* _list = list;
	list = new T[count - 1];
	for (int i = 0; i < _index; i++)
		list[i] = _list[i];
	for (int i = _index + 1; i < count; i++)
		list[i - 1] = _list[i];
	count--;
}

template<typename T>
inline void Liste<T>::RemoveAll(T& _item)
{
	while (Contains(_item))
		RemoveAt(FindOf(_item));
}

template<typename T>
inline bool Liste<T>::Contains(const T& _item)
{
	return FindOf(_item) != -1;
}

template<typename T>
inline int Liste<T>::Count()
{
	return count;
}

template<typename T>
inline void Liste<T>::Clear()
{
	if (count < 1)
		delete list;
	else
		delete[] list;
	list = nullptr;
	count = 0;
}

template<typename T>
inline void Liste<T>::Display()
{
	for (int i = 0; i < count; i++)
		std::cout << list[i] << std::endl;
}
