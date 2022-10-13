#pragma once
#include <initializer_list>
#include "Node.h"

template<typename T>
class List
{
private:
	Node<T>* head = nullptr;
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	int count = 0;
private:
	List() = default;
	List(const initializer_list<T>&  _tab);
	~List();

	void AddFirst(const T& _item);

};

template<typename T>
inline void List<T>::AddFirst(const T& _item)
{
	Node<T>* _newNode = new Node<T>(_item);
	if (head == nullptr)
		Node<T>* _newNode = new Node<T>(_item);
	if (head == nullptr) // met une sécurité et initialise tout les pointeur
	{
		head = _newNode;
		first = _newNode;
		last = _newNode;
	}
	else
	{
		_newNode->SetNext(first); // permet de pointer le bloc suivant 
		first->SetPrev(_newNode); // permet de définir les précédent en tant que le reste des bloc 
		head = first = _newNode; // permet de rassembler sur head 
	}
	count++;

}
