// exo 3 paramètre correction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion 

#pragma region infos
string firstName = "",
       lastName = "";
int age = 10; 
#pragma endregion 

#pragma region loc
string frLocFirstName = "écrivez votre prénom",
enLocFirstName = "set your firstname",
frLocFLastName = "ecrivez votre nom",
enLocLastName = "set your lastname",
frLocLocAgeName = "ecrivez votre age ",
enLocAgeName = "set your age";
#pragma endregion 

void SetFirstName(string _locLabel)
{
    cout << _locLabel << "\n";
    cin >> firstName;
}

void SetLastName(string _locLabel)
{
    cout << _locLabel << "\n";
    cin >> lastName;
}

void SetAge(string _locLabel)
{
    cout << _locLabel << "\n";
    cin >> age;
}

string GetFullContact()
{
    return firstName + " " + lastName + " " + to_string(age);
}

void ShowCntact()
{
    cout << GetFullContact();
}

int main()
{
    SetFirstName(enLocFirstName);
    SetLastName(enLocLastName);
    SetAge(enLocAgeName);
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
