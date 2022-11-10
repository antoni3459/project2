#pragma once
template<typename T>

class Node
{
private:
	Node* next = nullptr;
	Node* prev = nullptr;
	T data = nullptr;
public:
	Node() = default;
	Node(const Node* _next, const Node* _prev, const T _data);
	Node* Next() const;
	Node* Prev()const;
	T Data()const;
	void SetNext(const Node* _next);
	void SetPrev(const Node* _prev);
};

template<typename T>
inline Node<T>::Node(const Node* _next, const Node* _prev, const T _data)
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
inline Node<T>* Node<T>::Prev() const
{
	return prev;
}

template<typename T>
inline T Node<T>::Data() const
{
	return data;
}

template<typename T>
inline void Node<T>::SetNext(const Node* _next)
{
	next = _next;
}

template<typename T>
inline void Node<T>::SetPrev(const Node* _prev)
{
	prev=_prev
}
