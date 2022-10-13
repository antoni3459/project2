// polimorphie exo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

class Véhicule
{
protected:
    string color = "";
    int nbrWheels = 0;
    int nbrdoor = 0;
public:
    int NbrWheels(int _nbrWheels)
    {
        nbrWheels = _nbrWheels;
    }
};

class Car: public Véhicule
{
private:
    string name = "voiture";
public:
    string Name()
    {
        cout << name << endl;
        return name;
    }
    int  NbrWheels()
    {
        nbrWheels = 4; 
        cout << nbrWheels<< " roue "<<endl;
        return nbrWheels;
    }
    string Color()
    {
        color = " rouge ";
        cout << "la couleur est : "<<color << endl;
        return color;
    }
};

class Moto : public Véhicule
{
private:
    string name = "moto";
public:
    string Name()
    {
        cout << name << endl;
        return name;
    }
    int  NbrWheels()
    {
        nbrWheels = 2;
        cout << nbrWheels << endl;
        return nbrWheels;
    }
};


int main()
{
    /*Car name = Car();
    Car nbrWheels = Car();
    Car color = Car();
    name.Name();
    nbrWheels.NbrWheels();
    color.Color();*/

    Moto name = Moto();
    name.Name();
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
