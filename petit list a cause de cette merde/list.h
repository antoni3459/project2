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
	void RemoveAll(const T& _item);
	bool Contains(const T& _item);
	int Count();
	void Clear();
	void Display();
#pragma endregion method
};

#pragma region constructor
template<typename T>
List<T>::List(std::initializer_list<T> _tab)
{
	count = _tab.size();
	tab = new T[count];
	int _index = 0;
	for (T _item : _tab)
		tab[_index++] = _item;
	
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
#pragma endregion constructor

#pragma region method
template<typename T>
void List<T>::FinfOff(const T& _item) // return l'indice du bloc choisi
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
	for (int i = 0; i < count; i++)
	{
		tab[i] = _tmp[i];
	}
	tab[count] = _tab;
	count++;
}

template<typename T>
void List<T>::Remove(T _item)
{
	const int _index = FinfOff(_item); // ressort l'indice pour séléctionner le bloc 
	if (_index == -1) throw std::out_of_range("[List] =>can't find item !");
	RemoveAt(_index);
}

template<typename T>
void List<T>::RemoveAt(const int& _index)
{
	T* _tmp = tab;
	tab = new T[count - 1];
	for (int i = 0;i < _index;i++)// séléctionne le bon bloc
		tab[i] = _tmp[i];
	for (int i = _index + 1;i < count;i++)// enlève le lien du précedent 
		tab[i - 1] = _tmp[i];
	count--;
}

template<typename T>
void List<T>::RemoveAll(const T& _item)
{
	while (Contains(_item))
	{
		RemoveAt(FinfOff(_item));
	}
}

template<typename T>
bool List<T>::Contains(const T& _item)
{
	return FinfOff(_item) != -1; // vérifie si il existe avec l'indice de FinOff
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
inline void List<T>::Display()
{
	for (int i = 0; i < count; i++)
	{

		std::cout << tab[i] << std::endl;
	}
}
#pragma endregion method		
