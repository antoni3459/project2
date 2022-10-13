#include <iostream>
using namespace  std;

string defaultName = "John";

string enLoc = "My name is : ",
       frLoc = "Mon nom est :",
       spLoc = "Me llamo : ";

void ShowName(string _locLabel, string _name)
{
    cout << _locLabel << _name << "\n";
}
void SetDefaultName()
{
    cin >> defaultName;
}

int main()
{
    ShowName(frLoc,"Toto");
    ShowName(enLoc,"Machin");
    ShowName(spLoc,"Elephant");
    //SetDefaultName();
    ShowName(enLoc,defaultName);
    cout << defaultName; 
}
