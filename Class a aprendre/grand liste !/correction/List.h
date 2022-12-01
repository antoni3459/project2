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
};

template<typename T>
List<T>::List(const initializer_list<T>& _tab) // permet de créé un tableau d'élement inconnus 
{
    for (const T& _item : _tab)
        AddLast(_item); // permet que le premier élement sois à la premier place 
}

template<typename T>
inline List<T>::~List() // destructeur détruit la liste 
{
	Clear(); // appel la fonction qui suprime la mémoire initializer_list
}

template<typename T>
inline void List<T>::AddFirst(const T& _item)
{
	Node<T>* _newNode = new Node(_item);
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

template<typename T>
inline void List<T>::AddLast(const T& _item)
{
	if (head == nullptr)
	{
		AddFirst(_item); // renvoie à l'initialisation de AddFirst
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
	count = 0; // réinitilize tout less pointeur 
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
	_head->Prev()->SetNext(_head->Next());//le lien du bloc suivant
	_head->Next()->SetPrev(_head->Prev());//le lien du bloc d'avant
	delete _head;
	count--;
}

template<typename T>
inline void List<T>::RemoveFirst() //suprime le premier élément 
{
	const Node<T>* _head = head;
	head = _head->Next; // c'est 2 ligne permet de chopper le premiers bloc
	if (head != nullptr)
		head->Prev(nullptr);// la on sélectionne
	delete _head;
	count--;
}

template<typename T>
inline void List<T>::RemoveLast()
{
	const Node<T>* _last = last;
	last = _last->Prev(); //met en évidence le dernier élément mis 
	if (last != nullptr)
		last->SetNext(nullptr);
	delete _last;
	count--;
}

template<typename T>
inline bool List<T>::Contains(const T& _item)
{
	return Find(_item) != nullptr; // return si il existe le nombre choisis
}

template<typename T>
inline void List<T>::AddBefore(const int& _index, const T& _item)
{
	Node<T>* _head = Find(_index);
	if (_head == nullptr) return;
	if (_head->Prev() == nullptr) // vérifie si il y'a quelque chose avant 
	{
		AddFirst(_item); // si il y a pas c'est donc le premier
		return;
	}
	Node<T>* _newmode = new Node<T>(_item, _head, _head->Prev()); // créé un nouveau pointeur 
	_head->Prev()->SetNext(_newmode); // le pointe sur le précédant 
	_head->SetNext(_newmode);// prend cette place en s'ajoutant a ceux qui sont déjas present
	count++;
}

template<typename T>
inline void List<T>::AddAfter(const int& _index, const T& _item)
{
	Node<T>* _head = Find(_index);
	if (_head == nullptr) return;
	if (_head->Next() == nullptr)// vérifie si il y'a quelque chose après 
	{
		AddLast(_item);// si il y a pas c'est donc le dernier
		return;
	}
	Node<T>* _newmode = new Node<T>(_item, _head, _head->Next(), _head);
	_head->SetNext(_newmode); // même chose sauf que c'est juste la place d'après
	_head->SetNext(_newmode);

	count++;

}

template<typename T>
Node<T>* List<T>::Find(const T& _item)
{
	Node<T>* _head = head;
	while (_head != nullptr)
	{
		if (*_head == _item) return _head; // enregistre le nombre mis dans le bloc
	}
	return nullptr;
}

template<typename T>

inline void List<T>::Display()
{
	Node<T>* _head = head;
	while (_head != nullptr)
	{
		cout << _head << ", ";
	}
	cout << _head << endl;
}

template<typename T>
inline int List<T>::Count() const
{
	return count;
}