#include "Map.h"
#include <iostream>

int main()
{
    Map<int, std::string> tab = Map<int, std::string>();

    tab.Clear();

    tab.Insert(0, "thomas");
    tab.Insert(2, "yep");
 

    for (KeyValuePair<int, std::string> _pair : tab)
    {
        std::cout << _pair.Value() << std::endl;
    }
    return 0;
}

