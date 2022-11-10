// tableau dynamique.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int* ptrTab = nullptr;

int main()
{
	int* _tabInt = new int[10];
	
	for (size_t i = 0;i < 10; i++) // on peut changer directement le nombre de colonne et de ligne du tableau 
	{
		_tabInt[i] = i;
		cout << _tabInt[i] << endl;
	}
	cout << _tabInt << endl;
	cout << &_tabInt[0] << endl;// la place est identique a celle de la première entrée 
	cout << &_tabInt[1] << endl;//elle est différente aux autres 


	delete[] _tabInt;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
