#pragma once
#include "Data.h"
#include <initializer_list>
#include <iostream>
using namespace std;


template<typename T>
class List
{
private:
	Case<T>* head = nullptr;
	int count = 0;
public:
	List() = default;
	List(const initializer_list<T> _tab);
public:
	void Add(const T _item);
	void Clear();
	int Count() const;
	void Remove(const T _item);
	void RemoveAt(const T _index);
	void RemoveAll() const;
	bool Contains(const T _item) const;
	void Display();
};

template<typename T>
inline List<T>::List(const initializer_list<T> _tab)
{
	for (const T _item : _tab)
		Add(_item);
}

template<typename T>
inline void List<T>::Add(const T _item)
{
	if (head = nullptr)
	{
		cout << head << " " << _item << endl;
		Case<T>  _newNode =  Case<T>(_item);
		return;
	}
	else
	{

	}
}

template<typename T>
inline void List<T>::Remove(const T _item)
{
}

template<typename T>
inline void List<T>::RemoveAt(const T _index)
{
}

template<typename T>
inline void List<T>::RemoveAll() const
{
}

template<typename T>
inline bool List<T>::Contains(const T _item) const
{
	
}

template<typename T>
void List<T>::Display()
{
	Case<T>* _head = head;
	for (int i = 0; i < count; i++)
	{
		cout << _head->Data() << " ";
		_head = _head->_tab[i];
	}
	cout << endl;
}