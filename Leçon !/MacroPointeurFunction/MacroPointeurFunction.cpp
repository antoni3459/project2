//#include <iostream>
//
//void Display(const std::string& _msg)
//{
//    std::cout << _msg << std::endl;
//}
//
//class A
//{
//public:
//    void HelloKitty()
//    {
//        std::cout << "Hello Kitty" << std::endl;
//    }
//    void Add( int _a,  int _b)
//    {
//        return _a + _b;
//    }
//};
//class B :public A
//{
//public:
//    void Test()
//    {
//
//    }
//int main()
//{
//    //void (*ptr)(const std::string&);
//   /* ptr  = &Display;
//    ptr("Hello World");*/
//
//    //void (A::*ptr)();
//    //ptr = &A::HelloKitty;
//    //A a; // si A est un pointeur on fait :A* a =new A();
//    //(a.*ptr)();//                      et (a->*ptr)(); 
//
//   /* B* b = new B();
//    void (A:: * ptr)();
//    ptr = reinterpret_cast<void(A::*)()>(&B::Test);
//    (b->*ptr)();*/
//
//    A* a = new A();
//    typedef void (A::* Function)();;
//
//    Function _function = &A::HelloKitty;
//    (a->*_function)();
//    return 0;
//}

int main()
{

	return 0;
}