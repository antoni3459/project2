#pragma once
#include <initializer_list>
#include "Nod.h"
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

#pragma endregion f/p
#pragma region constructor
private:
	Node<T>* Find(const T& _item);
public:
	List() = default;
	List(const initializer_list<T>& _tab);
	~List();
#pragma endregion constructor
#pragma region method
public:
	void AddFirst(const T& _item);
	void AddLast(const T& _item);
	void Clear();
	void Remove(const T& _item);
	void RemoveFirst();
	void RemoveLast();
	bool Contains(const T& _item);
	void AddBefore(const int& _index, const T& _item);
	void AddAfter(const int& _index, const T& _item);
	void Display();
	int Count() const;
	T& At(const int& _index);
};

template<typename T>
List<T>::List(const initializer_list<T>& _tab) // permet de cr?? un tableau d'?lement inconnus 
{
    for (const T& _item : _tab)
        AddLast(_item); // permet que le premier ?lement sois ? la premier place 
}

template<typename T>
inline List<T>::~List() // destructeur d?truit la liste 
{
	Clear(); // appel la fonction qui suprime la m?moire initializer_list
}

template<typename T>
inline void List<T>::AddFirst(const T& _item)
{
	Node<T>* _newNode = new Node<T>(_item);
	if (head == nullptr) // met une s?curit? et initialise tout les pointeur
	{
		head = _newNode;
		first = _newNode;
		last = _newNode;
	}
	else
	{
		_newNode->SetNext(first); // permet de pointer le bloc suivant 
		first->SetPrev(_newNode); // permet de d?finir les pr?c?dent en tant que le reste des bloc 
		head = first = _newNode; // permet de rassembler sur head 
	}
	count++;

}

template<typename T>
inline void List<T>::AddLast(const T& _item)
{
	if (head == nullptr)
	{
		AddFirst(_item); // renvoie ? l'initialisation de AddFirst
		return;
	}
	Node<T>* _newNode = new Node<T>(_item, nullptr, last);
	//_newNode->SetPrev(last);
	last->SetNext(_newNode); // permet que les blocs suivant sois tout les bocs de la liste 
	last = _newNode;
	count++;
}

template<typename T>
inline void List<T>::Clear()
{
	
	if (count == 0 || count == 1) 
		delete head; // suprime le seul bloc de la liste 
	else
		delete[] head; // suprime tout les bloc de la liste 
	count = 0; // r?initilize tout less pointeur 
	last = nullptr;
	first = nullptr;
	head = nullptr;
}

template<typename T>
inline void List<T>::Remove(const T& _item)
{
	if (first == _item)
	{
		RemoveFirst();
		return;
	}
	if (last == _item)
	{
		RemoveLast();
		return;
	}

	const Node<T>* _head = Find(_item);
	if (_head == nullptr) return;
	_head->Prev()->SetNext(_head->Next());
	_head->Next()->SetPrev(_head->Prev());
	delete _head;
	count--;
}

template<typename T>
inline void List<T>::RemoveFirst()
{
	const Node<T>* _head = head;
	head = _head->Next;
	if (head != nullptr)
		head->Prev(nullptr);
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
	return Find(_item) != nullptr;
}

template<typename T>
inline void List<T>::AddBefore(const int& _index, const T& _item)
{
	Node<T>* _head = Find(_index);
	if (_head == nullptr) return;
	if (_head->Prev() == nullptr)
	{
		AddFirst(_item);
		return;
	}
	Node<T>* _newmode = new Node<T>(_item, _head, _head->Prev());
	_head->Prev()->SetNext(_newmode);
	_head->SetNext(_newmode);
	count++;
}

template<typename T>
inline void List<T>::AddAfter(const int& _index, const T& _item)
{
	Node<T>* _head = Find(_index);
	if (_head == nullptr) return;
	if (_head->Next() == nullptr)
	{
		AddLast(_item);
		return;
	}
	Node<T>* _newmode = new Node<T>(_item, _head, _head->Next(), _head);
	_head->SetNext(_newmode);
	count++;
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
inline int List<T>::Count() const
{
	return count;
}

template<typename T>
 T& List<T>::At(const int& _index) // permet de montrer la valeur 
{
	 if (_index <0 || _index >count) throw out_of_range("out of range !");
	 Node<T>* _head = head;
	 for (int i = 0; i < _index && _head->Next(); i++)
	 {
		 _head = _head->Next();
	 }
	 return _head->Data();
}
