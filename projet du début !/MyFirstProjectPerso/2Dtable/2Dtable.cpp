// 2Dtable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int sizeTab = 4;
int oneTab[] = { 1,2,3,4 };//one
int twoTab[4][4] = {
					{1,2,3,4},//0-> [0,1,2,3]
					{4,5,6,7},// 1-> [0,1,2,3]
					{8,9,10,11},// 2 -> [0,1,2,3]
					{12,13,14,15}//3-> [0,1,2,3]
};//4*4
int a[1][2] = {
	{0,1}
};

int b[2][2] = {
	{0,1},
{0,1}
};

int main()
{
	for (int i = 0;i < 4;i++)
	{
		std::cout << oneTab[i] << std::endl;
	}
	for(int i=0; i <4;i++)
	{
		fpr
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
