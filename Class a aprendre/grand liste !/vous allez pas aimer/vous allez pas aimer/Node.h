#pragma once
template<typename T>
class Node
{
private:
	Node* next = nullptr;
	Node* prev = nullptr;
	T data = T();
public:
	Node() = default;
	Node(const Node* _data, const Node* _next, const T& _prev);
	Node* Next() const;
	Node* Prev() const;
	T& Data();
	void SetNext(Node* _next);
	void SetPrev(Node* _prev);
};

template<typename T>
inline Node<T>::Node(const Node* _data, const Node* _next, const T& _prev)
{
	next = _next;
	prev = _prev;
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
inline T& Node<T>::Data()
{
	return data;
}

template<typename T>
inline void Node<T>::SetNext(Node* _next)
{
	next = _next;
}

template<typename T>
inline void Node<T>::SetPrev(Node* _prev)
{
	prev = _prev;
}
