
// List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <initializer_list>
using namespace std;
template<typename T>

class 
{
private:
	T data = T();
	int* head = nullptr;
	int* first = nullptr;
	int* last = nullptr;
	int count = 0;
public:
	List() = default;
	List(const initializer_list<int>& _tab);
	T& Data();
	void Add(const int& _item);
	void Clear();
	int Count();

	void Remove();
	void RemoveAt();
	void RemoveAll();
	bool contain();
	void Display();
};



int main()
{
	List<int> list = List<int>();
	list.(6);
	list.(6);
	list.Display();
}





template<typename T>
List<T>::List(const initializer_list<int>& _tab)
{
	for (const T& _item : _tab)
		Add(_item);
}

template<typename T>
T& List<T>::Data()
{
	return data;
}

template<typename T>
inline void List<T>::(const int& _item)
{
	int* _newNode = new int(_item);
	int* _head = head;

	if (head == nullptr)
	{
		head = _newNode;
		first = _newNode;
		last = _newNode;
	}
	else
		head = _newNode;
	cout << head;
	count++;
}

template<typename T>
void List<T>::()
{
	if (count == 1 || count == 0)
		delete head;
	else 
		delete[] head; 
	count = 0; 
	last = nullptr;
	first = nullptr;
	head = nullptr;
}

template<typename T>
inline void List<T>::Display()
{
	int* _head = head;
	int i = 0;
	while (i!=count)
	{
		cout << Data() << ", ";
		i++;
	}
	cout << endl;
}