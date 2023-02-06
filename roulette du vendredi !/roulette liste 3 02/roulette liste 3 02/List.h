#pragma once
#include <iostream>
#include <initializer_list>

template <typename T>
class List
{
private:
	int count = 0;
	T* list = nullptr;

public:
	List() = default;
	List(const std::initializer_list<T&> _list);
	List(const List& _copy);
	~List();

private:
	int FindOf(const T& _item);
public:
	void Add(const T& _item);
	void Remove(const T& _item);
	void RemoveAt(const T _index);
	void RemoveAll(const T& _index);
	bool Contains(const T& _item);
	void Clear();
	int Count();
	void Display();


};

template<typename T>
inline List<T>::List(const std::initializer_list<T&> _list)
{
	int count = 0;
	for (T listes : _list)
		list[listes] = _list;
}

template<typename T>
inline List<T>::List(const List& _copy)
{
	list = _copy.list;
}

template<typename T>
inline List<T>::~List()
{
	Clear();
}

template<typename T>
inline int List<T>::FindOf(const T& _item)
{
	for (int i = 0; i < count;i++)
		if (list[i] = _item)
			return i;
	return -1;
}

template<typename T>
inline void List<T>::Add(const T& _item)
{
	T* _list = list;
	list = new T[count];
	for (int i = 0;i < count;i++)
	{
		list[i] = _list[i];
	}
	list[count] = _item;
	count++;
}

template<typename T>
inline void List<T>::Remove(const T& _item)
{
	T* _list = list;
	list = new T[count];
	for (int i = 0;i < count;i++)
	{
		
	}
	count--;
}

template<typename T>
inline void List<T>::RemoveAt(const T _index)
{
}

template<typename T>
inline void List<T>::RemoveAll(const T& _index)
{
	while (Contains(_index))
		Remove(_index);
}

template<typename T>
inline bool List<T>::Contains(const T& _item)
{
	if (FindOf(_item) != -1)
	{
		std::cout << "true" << std::endl;
		return true;
	}
	else
	{
		std::cout << "false" << std::endl;
		return false;
	}
}

template<typename T>
inline void List<T>::Clear()
{
	if (count < 1)
		delete list;
	else
		delete[] list;

	list = nullptr;
	count = 0;
}

template<typename T>
inline int List<T>::Count()
{
	return count;
}

template<typename T>
inline void List<T>::Display()
{
	for (int i = 0;i < count;i++)
		std::cout << list[i] << std::endl;
}
