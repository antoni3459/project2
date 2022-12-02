#pragma once
#include "Node.h"
#include <initializer_list>
#include <iostream>

template <typename T>
class List
{
private :
	Node<T>* head = nullptr;
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	int count = 0;

public:
	List() = default;
	List(const Node<T>* head, const Node<T>* first, const Node<T>* last);
	~List();

private:
	Node<T>* Find(const T& _item);

public:
	void AddFirst(const T& _item);
	void AddLast(const T& _item);
	void Remove(const T& _item);
	void RemoveFirst();
	void RemoveLast();
	bool Contains(const T& _item);
	T& At(const int& _index);
	void AddBefore(const int _index,const T& _item);
	void AddAfter(const int _index, T& _item);
	int Count();
	void Display();
	void Clear();
};

template<typename T>
inline List<T>::List(const Node<T>* _head, const Node<T>* _first, const Node<T>* _last)
{
	head = _head;
	first = _first;
	last = _last;
}

template<typename T>
inline List<T>::~List()
{
	Clear();
}

template<typename T>
inline Node<T>* List<T>::Find(const T& _item)
{
	Node<T>* _head = new Node<T>();
	while (_head != nullptr)
	{
		if (_head->operator==(_item))
			return _head;
		head = head->Next();
	}
	return nullptr;
}

template<typename T>
inline void List<T>::AddFirst(const T& _item)
{
	Node<T>* _newNode = new Node<T>(_item);
	if (head == nullptr)
	{
		head = _newNode;
		first = _newNode;
		last = _newNode;
	}
	else
	{
		_newNode->SetNext(first);
		first->SetPrev(_newNode);
		head = first = _newNode;
	}
	count++;
}

template<typename T>
inline void List<T>::AddLast(const T& _item)
{
	Node<T>* _newNode = new Node<T>(_item);
	if (head == nullptr)
	{
		AddFirst();
		return;
	}
	Node<T>* _newNode = new Node<T>(_item, nullptr, last);
	last->SetNext(_newNode);
	last = _newNode;
	count++;
}

template<typename T>
inline void List<T>::Remove(const T& _item)
{
	if (*first == _item)
	{
		RemoveFirst();
		return;
	}
	if (*last == _item)
	{
		RemoveLast();
		return;
	}

	const Node<T>* _head = Find(_item);
	if (_head == nullptr)return;
	_head->Prev()->SetNext(_head->Next());
	_head->Next()->SetPrev(_head->Prev());
	delete _head;
	count++;
}

template<typename T>
inline void List<T>::RemoveFirst()
{
	const Node<T>* _head = head;
	head = _head->Next();
	if (head != nullptr)
		head->SetPrev(nullptr);
	delete _head;
	count--;
}

template<typename T>
inline void List<T>::RemoveLast()
{
	const Node<T>* _last = last;
	last = _last->Prev();
	if (last != nullptr)
		last->SetNext(nullptr);
	delete _last;
	count--;
}

template<typename T>
inline bool List<T>::Contains(const T& _item)
{
	if (Find(_item) != nullptr)
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
inline T& List<T>::At(const int& _index)
{
	if (_index<0 || _index>count) throw std::out_of_range("out of range !");
	Node<T>* _head = head;
	for (int i = 0;i < _index && _head->Next();i++)
		_head = _head->Next();
	return _head->Data();
}

template<typename T>
inline void List<T>::AddBefore(const int _index,const T& _item)
{
	Node<T>* _head = Find(_index);
	if (_head == nullptr)return;
	if (_head->Prev() == nullptr)
	{
		AddFirst();
		return;
	}
	Node<T>* _newNode = new Node<T>(_item, _head, _head->Prev());
	_head->Prev()->SetNext(_newNode);
	_head->SetNext(_newNode);
	count++;
}

template<typename T>
inline void List<T>::AddAfter(const int _index, T& _item)
{
	Node<T>* _head = Find(_index);
	if (_head == nullptr) return;
	if (_head->Next() == nullptr)
	{
		AddLast(_item);
		return;
	}
	Node<T>* _newmode = new Node<T>(_item, _head, _head->Next());
	_head->SetNext(_newmode); 
	count++;
}

template<typename T>
inline int List<T>::Count()
{
	return count;
}

template<typename T>
inline void List<T>::Display()
{
	Node<T>* _head = head;
	while (_head != nullptr)
	{
		cout << _head->Data() << ", ";
		_head = _head->Next();
	}
	cout << endl;
}

template<typename T>
inline void List<T>::Clear()
{
	if (count == 0 || count == 1)
		delete head;
	else
		delete[] head; 
	count = 0;
	last = nullptr;
	first = nullptr;
	head = nullptr;
}
