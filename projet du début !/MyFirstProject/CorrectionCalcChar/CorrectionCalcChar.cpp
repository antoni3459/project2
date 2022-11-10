// CorrectionCalcChar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 

int x, y; 

//return ++
//void TestMethod(bool _canWork)
//{
	// if(!player)
		// return; 
	//
	//car->speed(playerSpeed * 10); 
	//enemy->Attack(player);
	//
	//
//	if (_canWork == false)
//		return; 
//	cout << "OK";
//	cout << "OK";
//	cout << "OK";
//	cout << "OK";
//	cout << "OK";
//}
//
int Add(int _a, int _b)
{
	return _a + _b;
}
int Sub(int _a, int _b)
{
	return _a - _b;
}
int Multiply(int _a, int _b)
{
	return _a * _b;
}
int Divide(int _a, int _b)
{
	if (_b == 0)
		return 0;
	return _a / _b;
}
char ChooseSign()
{
	cout << "Set operator (+, *, /, -) : " << endl;
	char _tmpResult; 
	cin >> _tmpResult;
	return _tmpResult;
}
void SetMember()
{
	cout << "Set X member : " << endl;
	cin >> x; 
	cout << "Set Y member : " << endl;
	cin >> y;
}
void SelectCalculator(char _mode, int _x, int _y)
{
	if (_mode == '+')
		cout << "Result : " << Add(_x, _y);
	else if (_mode == '*' || _mode == 'x' || _mode == 'X')
		cout << "Result : " << Multiply(_x, _y);
	else if (_mode == '/' || _mode == ':')
		cout << "Result : " << Divide(_x, _y);
	else if (_mode == '-')
		cout << "Result : " << Sub(_x, _y);
	else
		SelectCalculator(ChooseSign(), x, y);

}
int main()
{
	SetMember();
	SelectCalculator(ChooseSign(), x, y);
}


