// CalcStockCorr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std; 

const int memSize = 10; 
string stock[memSize];
int memIndex = 0;

void ClearMemory()
{
	for (int i = 0; i < memSize; i++)
		stock[i] = "0";
}
void ReadMemory()
{
	cout << "Read current calc memory : \n"; 
	for (int i = 0; i < memSize; i++)
		cout << i+1 << " - " <<  stock[i] << endl;
}
void SetMemory(string _toSave)
{
	stock[memIndex] = _toSave;
	memIndex++;
	memIndex = (memIndex > memSize - 1) ? 0 : memIndex;
}
string Addition(float _a, float _b)
{
	float _c = _a + _b;
	return to_string(_a) + " + " + to_string(_b) + " = " + to_string(_c);
}
string Divide(float _a, float _b)
{
	float _c = _b == 0  ? 0 : _a / _b;
	return to_string(_a) + " / " + to_string(_b) + " = " + to_string(_c);
}
int main()
{
	ClearMemory();
	SetMemory(Addition(5, 2));
	SetMemory(Addition(10, 2));
	SetMemory(Addition(10, 2));
	SetMemory(Addition(20, 2));
	SetMemory(Divide(20, 2));
	SetMemory(Addition(100, 2));
	ReadMemory();
}
