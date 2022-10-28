// j'ai rien compris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>
#include "Action.h"
#include "Object.h"
#include "Func.h"
#include "IGame.h"

//class A :public Object
//{
//public:
//	void Test(float _a)
//	{
//		std::cout << _a << std::endl;
//	}
//	
//	int Add(const int _a, const int _b)
//	{
//		return _a + _b;
//	}
//	void Hello(const std::string& ,float _b)
//	{
//		std::cout << "Hello" << _b << std::endl;
//	}
//};
//
//void OnEnd(Object _intance, Action<float> _callback)
//{
//
//}

#define USER "thomas"

#define nameof(x) #x
#define Add(a, b) a+b
#define PURE_VIRTUAL()=0;
#define null nullptr


class A
{
public:
	virtual void Test() PURE_VIRTUAL()
};

void Display(Object* _o)
{
	std::cout << std::format("Is Interfarce: {}", _o->IsInterface());
	std::cout << std::format("Is Class: {}", _o->IsClass());
	std::cout << std::format("Is Abstract: {}", _o->IsAbstract());
	std::cout << "\n\n";
}

int main()
{
	//Object o;
	//o.SetBitMask(Interfarce);
	//Display(o);
	//Object o1;
	//o1.SetBitMask(Abstract);
	//Display(o1);

	/*Object* o = new Object();
	Display(o);*/

	IGame* game = new IGame();
	game->Test();
		//std::cout << Add(5, 10);

		/*
		Action<float> onTest = &A::Test;
		A* _a = new A();

		onTest.Invoke(_a, 5);
		onTest -= &A::Test;

		onTest.Invoke(_a, 5);

		A* _a = new A();
		OnEnd(_a, &A::Test);
		delete _a;*/

		/*Func<int,int, int> OnAdd = &A::Add;
		A* _instance = new A();
		const int _result = OnAdd.Invoke(_instance ,5, 10);
		std::cout << _result;*/

		/*A _a = A();
		Action<float> OnUpdate = &A::Test;
		Action<const std::string&, float> OnUpdate1 = &A::Hello;
		OnUpdate.Invoke(&_a, 5.0f);
		OnUpdate1.Invoke(&_a, "Hello Kitty: ", 5.0f);*/

		/*A _a = A();
		Action<float> OnUpdate = &A::Test;
		try
		{
			OnUpdate.Invoke(&_a, 5.0f);
		}
		catch (const Exception& _e)
		{
			std::cout << _e.ToString();
		}*/

		return 0;
}
