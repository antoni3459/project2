// correction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include "List.h"

using namespace std;
#pragma endregion 
int main()
{
	List<int> list = List<int>();

	list.AddFirst(5);
	try
	{
		list.At(10);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	list.Display();
	
}
