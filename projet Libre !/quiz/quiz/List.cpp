#include "List.h"

List::List(const std::initializer_list<int> _list)
{
	count = _list.size();
	liste = new int[count];
	int _index = 0;
	for (int _item : _list)
		liste[_index++] = _item;
}

List::List(const List& _copy)
{
	liste = _copy.liste;
}

List::~List()
{
	delete liste;
	liste = nullptr;
	count = 0;
}

void List::Add(int _x)
{
	int* _liste = liste;
	liste = new int[count + 1];
	for (int i = 0; i < count; i++)
	{
		liste[i] = _liste[i];
	}
	liste[count] = _x;
	count++;
}

bool List::Contains(int& _x)
{
	for (int i = 0; i < count; i++)
		if (liste[i] == _x && count <6)
			return true;
	return false;
}
