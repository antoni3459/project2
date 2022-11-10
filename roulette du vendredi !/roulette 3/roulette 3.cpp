
#include <iostream>
#include <string>


std::string a = "hello world";

void Reverse()
{
    int y = a.size();
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " " << a[y-1] << "\n";
        y--;
    }
}


int main()
{
    Reverse();
}

