
#pragma region includes
#include <iostream>
#include <string>

using namespace std; 
#pragma endregion

#pragma region user infos
string firstName = "",
       lastName = "";
int age = 18;
#pragma endregion

#pragma region loc
string  frLocFirstName = "Ecrivez votre prénom",
        enLocFirstName = "Set your firstname : ",
        frLocLastName = "Ecrivez votre nom",
        enLocLastName = "Set your lastname : ",
        frLocAge = "Ecrivez votre age",
        enLocAge = "Set your age : ";
#pragma endregion 

#pragma region set user data methods
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
void ShowContact()
{
    cout << GetFullContact();
}
#pragma endregion

int main()
{
    SetFirstName(enLocFirstName);
    SetLastName(enLocLastName);
    SetAge(enLocAge);
    ShowContact();
    return 0;
}
