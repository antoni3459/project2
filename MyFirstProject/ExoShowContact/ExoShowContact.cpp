#include <iostream>
#include <string>
using namespace std; 

//set first and last name
//déclaration paralelle 
int i,j;
//affectation groupée
int k = i = j = 10; 

string firstName = "Toto" ,
       lastName = "Machin",
       result = "" ;

/**
 * Prepare contact infos from firstname and lastname
 */
string GetContact()
{
    return  "Firstname is : \n"
            + firstName
            + "\n"
            + "Lastname is : \n"
            + lastName;  // concaténation
}

/**
 * Show contact UI
 */
void ShowContact()
{
    result = GetContact();
    cout << "Contact read : \n" << result; 
}

int main()
{
    ShowContact();
    return 0;
}
