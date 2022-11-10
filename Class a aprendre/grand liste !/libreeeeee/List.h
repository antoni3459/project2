#pragma once
#include <initializer_list>
#include "Node.h"

template<typename T>

class List
{
private:
	Node* head = nullptr;
	Node* first = nullptr;
	Node* last = nullptr;
	int count = 0;
public:
	List() = default;
	List(const initializer_list<T>& _tab);	
	~List();


	void AddFirst(const T& _item);
	void AddLast(const T& _item);
	void Remove(const T& _item);
	void RemoveFirst();
	void RemoveLast();
	void Clear();
	int Count() const;
};

template<typename T>
inline List<T>::List(const initializer_list<T>& _tab)
{
}

template<typename T>
inline List<T>::~List()
{
	Clear();
}

template<typename T>
inline void List<T>::AddFirst(const T& _item)
{
	Node<T>* newNode = new Node<T>(_item);
	if (head == nullptr)
	{
		head = newNode;
		first = newNode;
		last = newNode;
	}
	else
	{
		newNode->SetPrev(first);
		first->SetPrev(newNode);
		head = first = newNode;
	}
	count++;
}

template<typename T>
inline void List<T>::AddLast(const T& _item)
{
	if (head == nullptr)
	{
		AddFirst();
		return;
	}
	else
	{
		Node<T>* newNode = new Node<T>(_item, nullptr, last);
		last->SetPrev(newNode);
		Last = newNode;
	}
	count++;
}


template<typename T>
inline void List<T>::Clear()
{
	if (count == 0 || count == 1)
		head = nullptr;
	else
		head[] = nullptr;
	first = nullptr;
	last = nullptr;
	count = nullptr;
}

template<typename T>
inline int List<T>::Count()const
{
	return count;
}
