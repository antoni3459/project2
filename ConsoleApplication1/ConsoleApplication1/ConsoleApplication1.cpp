// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
template <typename T1, typename T2>
bool Instanceof(T1 _obj1, T2 _obj2)
{
	if (typeid(_obj1) == typeid(_obj2))
	{
		std::cout << "true";
		return true;
	}
	else
	{
		std::cout << "false";
		return false;
	}

}

int main()
{
	int a = 0;
	int c = 5;
	char b = '0';
	std::cout << Instanceof(a, c);
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
