#pragma once
#include <initializer_list>
using namespace std;
template<typename T>

class List
{
#pragma region f/p
private:
	T* tab = nullptr;
	int count = 0;
#pragma endregion f/p

#pragma region constructor 
public :
	List();
	List(const T& _item);
	List(initializer_list<T> _tab);
	~List();
#pragma endregion constructor 

#pragma region method
	void Add(const T& _item);
	void Clear();
	int Count();
	void Remove(const T& _index);
	void RemoveAll(const int& _index);
	void RemoveAt(const T& _index);


};

template<typename T>
inline void List<T>::Add(const T& _item)
{
	T* _tmp = tab;
	if (tab == nullptr)
		tab = _item;
	else
	{
		for (int i = 0; i < count; i++)
		{
			tab[i] = _tmp[i];
		}
		tab[count] = _item;
		count++;
	}
}

template<typename T>
inline void List<T>::Clear()
{
	if (count == 1 || count == 0)
		delete tab;
	else
		delete tab[];

}

template<typename T>
inline int List<T>::Count()
{
	return count;
}

