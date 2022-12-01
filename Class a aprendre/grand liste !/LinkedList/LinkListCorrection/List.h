#pragma once
#include <iostream>
#include "Node.h"
#include <initializer_list>
using namespace std;

template<typename T>
class List
{
#pragma region f/p
private:
	Node<T>* head = nullptr;
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	int count = 0;
#pragma endregion 
public:
	List() = default;
	List(const initializer_list<T>& _tab);
	~List();
private:
	Node<T>* Find(const T& _item);
public:
	void AddFirst(const T& _item);
	void AddLast(const T& _item);
	void Clear();
	void Remove(const T& _item);
	void RemoveFirst();
	void RemoveLast();
	bool Contains(const T& _item);
	inline void AddBefore(const T& _index, const T& _item);
	void AddAfter(const T& _index, const T& _item);
	void Display();
	int Count() const;
	T& At(const int& _index);
};




template<typename T>
List<T>::List(const initializer_list<T>& _tab) //initialize la list 
{
	for (const T& _item : _tab)
		AddLast(_item);
}

template<typename T>
List<T>::~List()
{
	Clear();
}

template<typename T>
Node<T>* List<T>::Find(const T& _item)
{
	Node<T>* _head = head;
	while (_head != nullptr)
	{
		if (*_head == _item) return _head;
	}
	return nullptr;
}

template<typename T>
void List<T>::AddFirst(const T& _item)
{
	Node<T>* _newNode = new Node<T>(_item); 
	if (head == nullptr) //initialize les pointeur 
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
void List<T>::AddLast(const T& _item)
{
	if (head == nullptr)
	{
		AddFirst(_item);
		return;
	}
	else
	{
		Node<T>* newNode = new Node<T>(_item, nullptr, last);
		last->SetPrev(newNode);
		last = newNode;
	}
	count++;

}

template<typename T>
void List<T>::Clear()
{
	if (count == 0 || count == 1)
		delete head;
	else
		delete[] head;
	count = 0;
	last = nullptr;
	first = nullptr;
}

template<typename T>
void List<T>::Remove(const T& _item)
{
	if (first == _item)
	{
		RemoveFirst();
		return;
	}
	else if (last == _item)
	{
		RemoveLast();
		return;
	}
	const Node<T>* _head = Find(_item);
	if (_head == nullptr) return;
	_head->Prev()->SetNext(_head->Next());
	_head->Next()->SetPrev(_head->Prev());


}

template<typename T>
void List<T>::RemoveFirst()
{
	const Node<T>* _head = head;
	head = _head->Next();
	if (head = nullptr)
		head->SetPrev(nullptr);
	delete _head;
	count--;
	if (count == 0)
	{
		head = first = last = nullptr;
	}

}

template<typename T>
void List<T>::RemoveLast()
{
	const Node<T>* _last = last;
	last = _last->Prev();
	if (last != nullptr)
		last->SetNext(nullptr);
	delete _last;
	count--;
}

template<typename T>
bool List<T>::Contains(const T& _item)
{
	return Find(_item) != nullptr;
}

template<typename T>
inline void List<T>::AddBefore(const T& _index, const T& _item)
{
	Node<T>* _head = Find(_index);
	if (_head == nullptr) return;
	if (_head->Prev() == nullptr)
	{
		AddFirst(_item);
		return;
	}
	Node<T>* _newNode = new Node<T>(_item, _head, _head->Prev());
	_head->Prev()->SetNext(_newNode);
	_head->SetNext(_newNode);
	count++;
}

template<typename T>
void List<T>::AddAfter(const T& _index, const T& _item)
{
	Node<T>* _head = Find(_item);
	if (_head == nullptr) return;
	if (_head->Next() == nullptr)
	{
		AddLast(_item);
		return;
	}
	Node<T>* _newNode = new Node<T>(_item, _head->Next(), _head);
	_head->Next()->SetPrev(_newNode);
	_head->SetNext(_newNode);
	count++;

}

template<typename T>
void List<T>::Display()
{
	Node<T>* _head = head;
	while (_head != nullptr)
	{
		cout << _head->Data() << std::endl;
		_head = _head->Next();
	}
	cout << endl;
}

template<typename T>
int List<T>::Count() const
{
	return count;
}


template<typename T>
T& List<T>::At(const int& _index)
{
	if (_index < 0 || _index > count) throw std::exception("Out of range !");
	Node<T>* _head = head;
	for (int i = 0; i < _index; i++)
	{
		_head = _head->Next();
	}
	return _head->Data();
}
