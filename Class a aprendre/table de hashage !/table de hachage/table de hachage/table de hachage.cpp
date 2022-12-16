#include <iostream>
#include "Hashtable.h"

int main()
{
	Hashtable<short, std::string> hash = Hashtable<short, std::string>();
	hash.InsertValueKey(1, "ça passe");

    for (KeyValue<short, std::string> _pair : hash)
    {
        std::cout << _pair.Value() << std::endl;
    }
    return 0;
}

