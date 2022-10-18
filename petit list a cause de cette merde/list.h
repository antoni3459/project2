#pragma once
#include <iostream>
#include <initializer_list>

template<typename T>

class List
{
#pragma region f/p
private :
	 T* tab = nullptr;
	 int count = 0;
#pragma endregion f/p

#pragma region constructor
public:
	List() = default;
	List(const std::initializer_list<T> _tab);
	List(const T& _copy);
	~List();
#pragma endregion constructor

#pragma region method
private:
	void FinfOff(const T& _item);
public:
	void Add(T _tab);
	void Remove(T _item);
	void RemoveAt(const int& _index);
	void RemoveAll();
	bool Contains();
	void At();
	int Count();
	void Display();
	void Clear();

#pragma endregion method
};

template<typename T>
 List<T>::List(std::initializer_list<T> _tab)
{
	tab = _tab;
}

template<typename T>
 List<T>::List(const T& _copy)
{
	tab = _copy.tab;
}

template<typename T>
 List<T>::~List()
{
	Clear();
}

template<typename T>
 void List<T>::FinfOff(const T& _item)
{
	for (int i = 0;i < count;i++)
		if (tab[i] == _item)
			return i;
	return -1;
}

template<typename T>
 void List<T>::Add(T _tab) 
{
	T* _tmp = tab;
	tab = new T[count + 1];
	for (int i = 0; i <= count; i++)
	{
		tab[i] = _tmp[i];
	}
	tab[count]=_tab;
	count++;
}

template<typename T>
 void List<T>::Remove(T _item)
{
}

template<typename T>
 void List<T>::RemoveAt(const int& _index)
{
	T* _tmp = tab;
	tab = new T[count - 1];
	for (int i = 0;i < _index;i++)
		tab[i] = _tmp[i];
	for (int i = _index + 1;i < count;i++)
		tab[i - 1] = _tmp[i];
	count--;
}

template<typename T>
 void List<T>::RemoveAll()
{

}

template<typename T>
 bool List<T>::Contains()
{
	return false;
}

template<typename T>
 void List<T>::At()
{
}

template<typename T>
 int List<T>::Count()
{
	return count;
}

template<typename T>
 void List<T>::Clear()
{
	if (count < 1)
		delete tab;
	else
		delete[] tab;
	count = 0;
}

template<typename T>
 void List<T>::Display()
{

}
