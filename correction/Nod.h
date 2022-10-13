#pragma once
#pragma region inculde
#include <iostream>

using namespace std;
#pragma endregion 
template <typename T>

class Node
{
private:
    Node* next = nullptr;
    Node* perv = nullptr;
    T data = T();
public:
    Node() = default;
    Node(const T& _data, Node* _next = nullptr, Node* _prev = nullptr);
    Node* Next() const;
    Node* Prev() const;
    T& Data();
    void SetNext(Node* _next);
    void SetPrev(Node* _perv);
};

template<typename T>

Node<T>::Node(const T& _data, Node* _next, Node* _prev) // appel tout les pointeur de cette classe dés qu'elle appeler 
{
    next = _next;
    perv = _prev;
    data = _data;
}

template<typename T>
Node<T>* Node<T>::Next() const
{
    return next;
}

template<typename T>
Node<T>* Node<T>::Prev() const
{
    return perv;
}

template<typename T>
T& Node<T>::Data() 
{
    return data;
}

template<typename T>
void Node<T>::SetNext(Node* _next) 
{
    next = _next;
}

template<typename T>
void Node<T>::SetPrev(Node* _prev)
{
    perv = _prev;
}