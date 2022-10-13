// temple monKu 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

class Node
{
public:
    int data;

    Node* next = nullptr;
    Node(int _data, Node* _next = nullptr)
    {
        data = _data;
        next = _next;
    }
};

class List
{
private :
    Node* tree = nullptr;
    Node* first = nullptr;
    Node* last = nullptr;
    int count = 0;
public:
    List() = default;
    List(initializer_list < int> _tab)
    {
        for (int _item : _tab)
        {
            AddLast(_item);
        }
    }
    void AddFirst(int _data)
    {
        if (tree == nullptr)
        {
            first = last 
        }
        else
        {
            Node* _newNode = new Node(_data, head);
            head = _newNode;
        }
    }
    void AddLast(int _data)
    {
        if (tree == nullptr)
        {
            AddFirst(_data);
            return;
        }
       
        while (tree->next != nullptr)
        {
            head=head->next;
        }
        head->next = new Node(_data);
        
    } 

    void AddAfter(int _data)
    {
        if (head == nullptr)
        {
            head = new Node(_data);
        }
        else
        {
            head->next = new Node(_data);
        }
    }

    void Clear()
    {
        delete head; 
        head = nullptr;
        
    }

    bool Contains(int _data)
    {
        Node* _tree = head;
        while (_tree != nullptr)
        {
            if (_tree->data == _data) return true;
            _tree = _tree->next;

        }
        return false;
        
    }
    
    void RemoveFirst()
    {
        Node* _tree = tree;
        tree = _tree->next;
        delete _tree;
        count--;
    }

    void RemoveLast()
    {
        Node* _tree = tree;
        while (_tree->next->next != nullptr)
        {
            _tree = _tree->next;
        }
        _tree = _tree->next;
        last = _tree;
        delete _tree;
        count--;
    }
    void Remove(int _item)
    {
        Node* _tree = tree;
        if (_tree == first)
        {
            RemoveFirst();
        }
        else if (_tree == last)
        {
            RemoveLast();
        }
        else
        {
            while (_tree != nullptr && _tree->data != _item)
            {
                _tree = _tree->next;
            }
            if (_tree == nullptr)return;
            _tree->prev->next = tree->next;
            _tree->next->prev = tree->prev;
        }
    }
    Node* Find(int _item)
    {
        Node* _tree = tree;
        while (_tree != nullptr && _tree->data != _item)
            _tree = _tree->next;
        return tree;
    }
    void AddBefore(int _index, int _item)
    {
        Node* _tree = tree;
        if (_tree->prev
    }
    void AddAfter(int index, int _item)
    {
        Node* _tree = Find();
            if (_tree == nullptr) return;
            if (_tree->next == nullptr)
            {
                AddLast(_items);
                    return
            }
    }

    void Display()
    {
        while (head != nullptr)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
   
    int& operator[] (int _index)
    {
        int _result = -1;
        if (_index <0 || _index > count)
            return _result;
        Node* _tree = tree;
        int _currentIndex = _index;
        while (_currentIndex > 0 && _tree != nullptr)
        {
            _currentIndex--;
            _tree = _tree->next;
        }
        if (_tree == nullptr) return _result;
        return _tree->data;
    }
};

int main()
{
    List list = List();
    list.AddFirst(6);
    list.AddAfter(4);
    list.AddAfter(5);
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
