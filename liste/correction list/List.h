#pragma once
#include <initializer_list>
#include <stdexcept>
using namespace std;

template<typename T>

class List
{
#pragma region f/p
private :
	int count = 0;
	T* tab = nullptr;
#pragma endregion f/p

#pragma region constructor
public:
	List();
	List(initializer_list<T> _tab);
	List(const List& _copy);
	~List();
#pragma endregion constructor
#pragma region method
private:
	void FinfOff(const T& _item);
public:
	void Add(const T& _item);
	void Clear(const bool _destroyNull=false );
	int Count();
	void Remove(const T& _item);
	void RemoveAll(const int& _item);
	void RemoveAt(const int& _index);
	void Contains(const T& _item);
#pragma endregion method
#pragma region operator
public :
	T& operator[](int _index);
#pragma endregion operator

};

#pragma region constructor

template<typename T>
List<T>::List()
{
	Clear(true);
}

template<typename T>
inline List<T>::List(initializer_list<T> _tab)
{
	count = _tab.size();
	tab = new T[count];
	for (const T _item : _tab)
		Add(_item);
}
template<typename T>
inline List<T>::List(const List& _copy)
{
	for (int i = 0; i < _copy.count;i++)
		Add(_copy.tab[i]);
}
template<typename T>
inline List<T>::~List()
{
	Clear();
}
template<typename T>
inline void List<T>::FinfOff(const T& _item)
{
	for (int i = 0;i < count;i++)
		if (tab[i] == _item)
			return i;
	return -1;

}
template<typename T>
inline void List<T>::Add(const T& _item)
{
	T* _tmp = tab;
	tab = new T[count + 1];
	for (int i = 0;i < count;i++)
		tab[i]= _tmp[i];
	tab[count] = _item;
	count++;
}
template<typename T>
inline void List<T>::Clear(const bool _destroyNull)
{
	if (count > 0)
		delete[] tab;
	else delete tab;
	count = 0;
	tab = new T[0];
}
template<typename T>
inline int List<T>::Count()
{
	return count;
}
template<typename T>
inline void List<T>::Remove(const T& _item)
{
	const int _index = FinfOff(_item);
	if (_index == -1) throw out_of_range("[List] =>can't find item !");
	RemoveAt(_index);
}
template<typename T>
inline void List<T>::RemoveAll(const int& _item)
{
	while (Contains(_item))
	{
		RemoveAt(FinfOff(_item));
	}
}
template<typename T>
inline void List<T>::RemoveAt(const int& _index)
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
inline void List<T>::Contains(const T& _item)
{
	return FinfOff(_item) != -1;
}
template<typename T>
inline T& List<T>::operator[](int _index)
{
	return tab[_index];
}
#pragma endregion constructor
