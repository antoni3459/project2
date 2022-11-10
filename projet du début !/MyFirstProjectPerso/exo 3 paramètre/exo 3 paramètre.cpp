// exo 4 paramètre.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string defaultname = " ";
string firstname = "";
string age = " ";

void ShowName(string _locLabel, string _name) // _name est un paramètre et on peut en mettre autant qu'on veut 
{
	cout << _locLabel << _name<< "\n";
}

void SetDefaultName()
{
	cin >> defaultname;
}

void SetFirstName()
{
	cin >> firstname;
}

void SetAge()
{
	cin >> age;
}

int main()
{
	ShowName("My name is :" , "toto"); // toto change le paramètre 
	ShowName("je m'appel : " , "machin");
	ShowName("Me llamo : " , "elephant");
	SetDefaultName();
	ShowName("je m'appel : ", defaultname);
	SetFirstName();
	ShowName("mon nom : ", firstname);
	SetAge();
	ShowName("mon age est : ", age);
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
