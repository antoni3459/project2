
// correction cpnveteur.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma region inculde
#include <iostream>
#include <string>

using namespace std;
#pragma endregion 

//1 - convertir des valeurs
//2 - programmer les formules de conversion 
//3 - m-> feet 
//4 -cin / out - 1 choisir lz nombre le mode 2 entrer la valeur 
//5 result

#pragma region feet/metre

string GetFeetFromMeter(float _meter)
{
    float _result = _meter * 3.28f;
    return to_string(_meter) + " m to feet is " + to_string(_result) + "ft \n";
}

string GetFeetFromFeet(float _feet)
{
    float _result = _feet / 3.28f;
    return to_string(_feet) + " ft to metre is " + to_string(_result) + "m \n";

}

#pragma endregion

#pragma region kmh/knot
string GetKmhFromKts(float _knots)
{
    float _result = _knots * 1.852f;
    return to_string(_knots) + "km/h to kts is = " + to_string(_result) + "knot\n";
}

string GetKmhFromKts(float _kmh)
{
    float _result = _kmh / 1.852f;
    return to_string(_kmh) + "knot to kmh is = " + to_string(_result) + "kmh\n";
}

#pragma endregion 

#pragma region feet/metre
string GetCelsusFromFar(float _celsus)
{
    float _result = (_celsus * (9 / 5)) + 32;
    return to_string(_celsus) + " far to celsus is " + to_string(_result) + "celsus \n";
}

string GetKtsFromKmh(float _far)
{
    float _result = (_far * (9 / 5)) - 32;
    return to_string(_far) + " celsus to far is " + to_string(_result) + "far \n";
}
#pragma endregion


string GetLFromUsGal(float _l)
{
    float _result = _l / 3.7;
    return to_string(_l) + " gallon to _l is " + to_string(_result) + "_l \n";
}

#pragma en

float GetValueToConvert()
{
    cout << "donne une valeur a convertire : " << endl;
    float _value;
    cin >> _value;
    return _value;
}

void ConverterMenu()
{
    cout << "1 - convert feet to meter" << endl;
    cout << "2 - convert meter to feet" << endl;
    cout << "3 - convert kmh to kts" << endl;
    cout << "4 - convert kys to kmh" << endl;
    cout << "5 - convert c to f" << endl;
    cout << "6 - convert F to C" << endl;
    cout << "7 - convert L to G" << endl;
    cout << "8 - convert G to L" << endl;
    cout << "[Select number from 1 to 8] : " << endl;
    char _imput;
    cin >> _imput;
    if (_imput == '1')
        cout << GetFeetFromMeter(1);
    else if (_imput == '2')
        cout << GetFeetFromFeet(1);
    else if (_imput == '3')
        cout << GetKmhFromKts(1);
    else if (_imput == '4')
        cout << GetKtsFromKmh(1);
    else if (_imput == '5')
        cout << GetLFromUsGal(1);
}






int main()
{
    cout << GetFeetFromMeter(1);
    GetFeetFromFeet(1);
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
