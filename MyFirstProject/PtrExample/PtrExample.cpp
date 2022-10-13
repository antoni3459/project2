// PtrExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int a = 5, b = 6, c = 10; 

int d = 498743213;
int* notCopy = nullptr;
int* ptrA = nullptr, *ptrB = nullptr; 

int Example()
{
	int* _a = new int(54);
	int _b = *_a;
	delete _a;
	return _b;
}

void SwapAB(int * _a, int * _b)
{
	int _tmp = *_a;
	*_a = *_b; 
	*_b = _tmp; 
	//_a = _b;
	//_b = _tmp;
}
int Test(int _a)
{
	int* _tmp = new int(_a); 
	int _r = *_tmp * 2;
	delete _tmp;
	return _r; 
}

int* TestPtr(int _a)
{
	return &_a;
}

int main()
{
	std::cout << Test(10) << std::endl;
	std::cout << TestPtr(10) << std::endl;
	return 0;
	std::cout << Example() << std::endl;
	std::cout << ptrB << std::endl; 
	ptrB = new int(10);
	std::cout << ptrB << std::endl;
	std::cout << *ptrB << std::endl;


	int* _i = (int*)malloc(sizeof(15)); 
	free(_i);

	int* _integer = new int(5);
	std::cout << _integer << std::endl;
	std::cout << *_integer << std::endl;
	*_integer = 100;
	std::cout << *_integer << std::endl;
	delete _integer;

	notCopy = &d; 
	std::cout << d << std::endl;
	*notCopy = 0;
	//notCopy....
	/*std::cout << a <<  " " << b << std::endl;
	SwapAB();
	std::cout << a << " " << b << std::endl;
	std::cout << a << " " << b << std::endl;*/
	std::cout << a << " " << b << std::endl;
	SwapAB(&a, &b);
	std::cout << a << " " << b << std::endl;
	//ptrA = &a;
	//std::cout << ptrA << std::endl;
	//std::cout << *ptrA << std::endl;
	//*ptrA = 67; 
	//std::cout << *ptrA << std::endl;
	//std::cout << a << std::endl;

	//ptrA = &b; 
	//std::cout << ptrA << std::endl;
	//std::cout << *ptrA << std::endl;
	//ptrA = &c;
	//std::cout << ptrA << std::endl;
	//std::cout << *ptrA << std::endl;

	delete ptrB;
}

