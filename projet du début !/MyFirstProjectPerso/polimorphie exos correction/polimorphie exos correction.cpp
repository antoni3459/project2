// polimorphie exos correction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

class Vehicule
{
private:
    string name = "";
public:
    string Name()
    {
        return name;
    }
public:
    Vehicule() = default;
    Vehicule(const string _name)
    {
        name = _name;
    }
};
class LandVehicule :public Vehicule
{
protected:
    int wheels = 0;
public:
    int Wheels()
    {
        return wheels;
    }
    LandVehicule() = default;
    LandVehicule(const string _name) : Vehicule(_name) {}
};


class Plane :public Vehicule
{
private:
    int wheels = 0;
    int engine = 0;
public:
    int Wheels()
    {
        return wheels;
    }
    int Engine()
    {
        retun  engine;
    }
public:
    Plane() = default;
    Plane(const string _name, int _wheels = 8, int _engine = 2) : Vehicule(_name)
    {
        wheels = _wheels;
        engine = _engine;
    }
};


int main()
{


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
