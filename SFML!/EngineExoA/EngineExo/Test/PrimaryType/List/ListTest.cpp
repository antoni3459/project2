#include "ListTest.h"
#include "../../../Engine/PrimaryType/Boolean/Boolean.h"
#include "../../../Engine/PrimaryType/List/List.h"
#include <iostream>

void Test::ListTest::Test()
{

	Engine::PrimaryType::List<Engine::PrimaryType::FString> tabStr = {"a", "b", "c"};

	checkLow((tabStr.Count() == 3), "tabStr is not equal to 3")
	checkLow((tabStr[0] == "a"), "tabStr[0] is not equal to a")

	const size_t _index = tabStr.Find("a");
	checkLow((_index == 0), "tabStr.Find(a) is not equal to 0")

	LOG(tabStr)


	tabStr.Remove("b");
	checkLow((tabStr.Count() == 2), "tabStr.Count is not equl to 2 ")

	LOG(tabStr)




	/*Engine::PrimaryType::List<int> tab = { 0,1,2,3,4,5,6,7,8,9 };

	checkLow((tab.Count() == 10), "tab is not equal to 10")
	checkLow((tab[0] == 0), "tab[0] is not equal to 0")

	const size_t _index = tab.Find(5);
	checkLow((_index == 5), "tab.Find(5) is not equal to 5")

	LOG(tab)

	tab.Remove(3);
	checkLow((tab.Count() == 9), "tab.Count is not equl to 9 ")

	LOG(tab)*/

}
