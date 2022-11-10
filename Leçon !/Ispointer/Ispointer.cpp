// Ispointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IsPointer.h"
template <typename T>
struct Ispointeur { enum {Value = false }; };


template <typename T>
struct Ispointeur<T*> { enum {Value = true }; };

template <typename T>
struct Ispointeur<const T> { enum {Value = Ispointeur<T>::Value}; };

template <typename T> struct RemoveConst { typedef T Type;};
template <typename T> struct RemoveConst<const T> {typedef T Type;};


template <typename T> struct RemovePointer {    typedef T Type;};
template <typename T> struct RemovePointer<T*> {   typedef T Type;};


template <typename T> struct RemoveReference {    typedef T Type;};
template <typename T> struct RemoveReference<T&> {   typedef T Type;};
template <typename T> struct RemoveReference<T&&> {   typedef T Type;};


template <typename T>
typename RemoveReference<T>::Type&& MowTemp(T && obj)
{
    typedef typename RemoveReference<T>::Type CasType;
    return (CasType&&)obj;

};

template <typename T>
void Swap(T& a, T& b)
{
    T _tmp = MoveTemp(a);
    a = MowTemp(b);
    b = MowTemp(_temp);
}

template <typename T, size_t N> size_t GetConst(T(&container)[N]) { return;}
template <typename T, size_t N> size_t GetConst(T(&&container)[N]) { return;}
template <typename T, size_t N> size_t GetConst(const T(&container)[N]) { return;}
template <typename T, size_t N> size_t GetConst(const T(&&container)[N]) { return;}
template <typename T>size_t GetConst(std::initializer_list<T> list) {    return list.size();}
template <typename T>auto GetConst(T&& container)->decltype (container.count())
{   
    return container.count();
}

typedef unsigned  char int8;
typedef unsigned short int16;
typedef unsigned int int32;
typedef unsigned long long int64;
typedef signed char int8;
typedef short int16;
typedef int int32;
typedef long long int64;
typedef unsigned  char byte;

#define DEPRECATED(message)[[deprecated(message",please une Test1")]]

template <typename T, typename SizeType=int32>
class Array
{
private :
    T* _tab = new T[0];
    SizeType size = 0;
public:
    DEPRECATED("Test is deprecated use Test1")
    void Test()
    {
        
    }
    void Test1()
    {

    }
    };


int main()
{
    Array<int> arr;
    
    //std::cout << Ispointeur<const int*>::Value<<std::endl;
    //std::cout << Ispointeur<const int>::Value<<std::endl;
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
