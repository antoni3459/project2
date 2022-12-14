#include <iostream>
#include "Hashtable.h"

int main()
{
	Hashtable<int, std::string> hash = Hashtable<int, std::string>();
	hash.InsertValueKey(0, "ça passe");
}

