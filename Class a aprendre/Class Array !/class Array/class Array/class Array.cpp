#include <iostream>

template<typename T>
class Array
{
private:
    int count = 0;
    T* tab = nullptr;
public:
    Array(int _count)
    {
        count = _count;
        tab = new T[count];
    }

    Array(T _item, int _count)
    {
        count = _count;
        tab = new T[count]; //met les item dans la liste 
        for (int i = 0; i < count; i++)
        {
            tab[i] = _item;
        }
    }

    Array(std::initializer_list<T> _tab)
    {
        tab = new T[_tab.size()];
        count = _tab.size();
        int index = 0;
        for (T _item : _tab)
        {
            tab[index] = _item;
            index++;
        }
    }

    T& GetAt(int _index)
    {
        return tab[_index];
    }

    T& GetFront()
    {
        return tab[count - 1];
    }

    T GetBack()
    {
        return tab[0];
    }

    T& operator[](int _index)
    {
        return tab[_index];
    }

    bool operator==(const Array& _other)
    {
        if (count != _other.count) return false;
        for (int i = 0; i < count; i++)
        {
            if (tab[i] != _other.tab[i]) return false;
        }
        return true;
    }

    bool operator!=(const Array& _other)
    {
        return !this->operator==(_other);
    }

    void Resize(int _count)
    {
        T* _tempTab = tab;

        tab = new T[_count];
        for (int i = 0; i < count; i++)
        {
            tab[i] = _tempTab[i];
        }
        count = _count;
    }
};





int main()
{
}