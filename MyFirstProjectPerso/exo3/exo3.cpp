// exo3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string value = "Antoni \n";

string Firstname()
{
    return value = "Praitano \n";
}

string Age()
{
    return value = "19ans \n";
}

string Hobby()
{
    cout << "mon hobby c'est le ";
    return value = "basket \n";
}
int i, j; // déclaration parallèle 
int k = i = j == 10; // affectation groupé 
string firstName = "toto";
string lastName = "machin";

string GetContact() // fonction qui fait 
{
    return "Firstname is : \n"
           + firstName
           + "\n"
           + "Lastname is : \n"
           + lastName; // conccaténation
}

void ShowContact() // fonction qui affiche 
{
    cout << "Contact read : \n" << GetContact();
}


int main()
{
    ShowContact();
    return 0;


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
