#include <iostream>
#include "Node.h"
#include "List.h"




int main()
{
    List<int> _list = List<int>();
    _list.AddFirst(10);
    _list.AddLast(50);

    
    _list.Display();
}


/*m�thods qui fonctionnent :
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