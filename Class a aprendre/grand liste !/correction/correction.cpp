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
	list.AddFirst(6);
	list.AddLast(10);
	list.AddFirst(50);
	list.Display();
	list.Clear();
	list.Display() ;
	
}
