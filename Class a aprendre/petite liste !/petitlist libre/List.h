#pragma once
#include <initializer_list>
#include <iostream>
template <typename T>
class List
{
#pragma region f/p

private:
	int count = 0;
	T* tab = nullptr;

#pragma endregion f/p

#pragma region constructeur

public:
	List() = default;
	List(std::initializer_list<T> _tab);
	List(const T& _copy);
	~List();

#pragma endregion constructeur

#pragma region method
private: 
	int FinfOf(T _items);
public:
	void Add( T _insert);
	void Remove( T _items);
	void RemoveAt(const int& _items);
	void RemoveAll(T& _items);
	bool Contains(T& _items);
	int Count();
	void Clear();
	void Display();


#pragma endregion method


};

template<typename T>
inline List<T>::List(std::initializer_list<T> _tab)
{
	tab = _tab;
}

template<typename T>
inline List<T>::List(const T& _copy)
{
	tan = _copy.tab;
}

template<typename T>
inline List<T>::~List()
{
	Clear();
}

template<typename T>
inline int List<T>::FinfOf(T _items)
{
	for (int i = 0; i < count; i++)
		if (tab[i] == _items)
			return i;
	return -1;
}

template<typename T>
inline void List<T>::Add(T _insert)
{
	T* _tmp = tab;
	tab = new T[count + 1];
	for (int i = 0; i < count; i++)
	{
		tab[i] = _tmp[i];
	}
	tab[count] = _insert;
	count++;
}

template<typename T>
inline void List<T>::Remove(T _items)
{
	const int index = FinfOf(_items);
	if (index == -1)
		throw std::out_of_range("[List] =>can't find item !");
	RemoveAt(index);
}

template<typename T>
inline void List<T>::RemoveAt(const int& _items)
{
	T tmp = tab;
	tab = new T[count-1];
	for (int i = 0; i < _items;i++)
		tab[i] = tmp[i];
	for (int j = _items + 1; j < count; j++)
		tab[j - 1] = tmp[j];
	count--;
}

template<typename T>
inline void List<T>::RemoveAll(T& _items)
{
	while (Contains(_items))
		RemoveAt(FinfOf(_items));
}

template<typename T>
inline bool List<T>::Contains(T& _items)
{
	return FinfOf(_items) !=-1;
}

template<typename T>
inline int List<T>::Count()
{
	return count;
}

template<typename T>
inline void List<T>::Clear()
{
	if (count <= 1)
		delete tab;
	else
		delete[] tab;
	count = 0;
}

template<typename T>
inline void List<T>::Display()
{
	for (int i = 0; i < count; i++)
		std::cout << tab[i] << std::endl;
}
