// exo 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion 

#pragma region infos
string name = "",
       firstName = "",
       hobby = "";
int age = 0;
#pragma endregion 

#pragma region questions
string getName = "Comment tu tappel ?",
       getFirstName = "Quel est ton nom ?",
       getAge = "Quel est ton age ?",
       getHobby = "Quel est ton hobby ?";
#pragma endregion 

void Name(string _locLabel)// on recupère le prénom
{
    cout << _locLabel << "\n";
    cin >> name;
}

void FirstName(string _locLabel)
{
    cout << _locLabel << "\n";
    cin >> firstName;
}

void Hobby(string _locLabel)
{
    cout << _locLabel << "\n";
    cin >> hobby;
}

void Age(string _locLabel)
{
    cout << _locLabel << "\n";
    cin >> age;
}

string GetFulContact()// on rassemble les donné 
{
    return name + " " + firstName + " " + to_string(age) + " " + hobby;
}

void ShowCntact()// onenvoi les donné dans la conssole
{
    cout << GetFulContact();
}



int main()
{
    Name(getName);
    FirstName(getFirstName);
    Age(getAge);
    Hobby(getHobby);
    ShowCntact();
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
