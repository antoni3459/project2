#pragma once
template <typename T>
class Node
{
private:
	Node* next = nullptr;
	Node* prev = nullptr;
	T data = T();

public:
	Node() = default;
	Node(const T& _data, Node* _next = nullptr, Node* _prev = nullptr);
	Node* Next();
	Node* Prev();
	T Data();
	void SetNext(Node* _next);
	void SetPrev(Node* _prev);
	bool operator== (T& _item);
	operator T();
};

template<typename T>
inline Node<T>::Node(const T& _data, Node* _next, Node* _prev)
{
	next = _next;
	prev = _prev;
	data = _data;
}

template<typename T>
inline Node<T>* Node<T>::Next()
{
	return next;
}

template<typename T>
inline Node<T>* Node<T>::Prev()
{
	return prev;
}

template<typename T>
inline T Node<T>::Data()
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

template<typename T>
inline bool Node<T>::operator==(T& _item)
{
	return data == _item;
}

template<typename T>
inline Node<T>::operator T()
{
	return data;
}
