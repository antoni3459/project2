// j'ai rien compris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Action.h"
#include "Object.h"

class A :public Object
{
public:
	void Test(float _a)
	{
		std::cout << _a << std::endl;
	}

	void Hello(float _b)
	{
		std::cout << "Hello" << _b << std::endl;
	}
};

int main()
{
	Action<float> onTest = &A::Test;
	A* _a = new A();

	onTest.Invoke(_a, 5);
	onTest -= &A::Test;

	onTest.Invoke(_a, 5);


	delete _a;
	return 0;

}


