#include <iostream>
#include "Node.h"
#include "List.h"




int main()
{
    List<int> _list = List<int>();
    _list.AddLast(10);
    _list.AddLast(85);
    _list.AddFirst(1);
    try
    {
        _list.At(10);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    _list.Display();
}


/*méthods qui fonctionnent :
-AddFirst
-AddLast
-RemoveLast
-Display

methods qui ne fonctionnent pas:
-AddBefore
-AddAfter
-Remove
-RemoveFirst
-Clear
-Contains

*/