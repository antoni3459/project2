// ConvertCorrection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
//4 - cin / out - 1 choisir le mode 2 entrer la valeur 
//5 result 

#pragma region Feet/Meter
string GetFeetFromMeter(float _meter)
{
    float _result = _meter * 3.28f;
    return to_string(_meter) + " m to feet is = " + to_string(_result) + " ft\n";
}
string GetMeterFromFeet(float _feet)
{
    float _result = _feet / 3.28f;
    return to_string(_feet) + " ft to meter is = " + to_string(_result) + " m\n";
}
#pragma endregion Feet/Meter
#pragma region Kmh/Knots
string GetKmhFromKts(float _knots)
{
    float _result = _knots * 1.852f;
    return to_string(_knots) + " kts to km/h is = " + to_string(_result) + " km/h\n";
}
string GetKtsFromKmh(float _kmh)
{
    float _result = _kmh / 1.852f;
    return to_string(_kmh) + " km/h to kts is = " + to_string(_result) + " kts\n";
}
#pragma endregion Kmh/Knots
#pragma region C/F
string GetCelciusFromF(float _fTemp)
{
    float _result = (_fTemp - 32) * 0.6f;
    return to_string(_fTemp) + " F to C is = " + to_string(_result) + " C\n";
}
string GetFahrFromC(float _cTemp)
{
    float _result = (_cTemp *  1.8f) + 32;
    return to_string(_cTemp) + " C to F is = " + to_string(_result) + " F\n";
}
#pragma endregion C/F
#pragma region L/GUS
string GetUSGalFromL(float _l)
{
    float _result = _l / 3.8f;
    return to_string(_l) + " L to US Gallon is = " + to_string(_result) + " G/US\n";
}
string GetLFromUSGal(float _gal)
{
    float _result = _gal * 3.8f;
    return to_string(_gal) + " US Gallon to L is = " + to_string(_result) + " L\n";
}
#pragma endregion L/GUS
float GetValueToConvert()
{
    cout << "Enter value to convert : " << endl;
    float _value; 
    cin >> _value;
    return _value; 
}
void ConverterMenu()
{
#pragma region menu 
    cout << "1 - Convert feet to meter" << endl;
    cout << "2 - Convert meter to feet" << endl;
    cout << "3 - Convert kmh to kts" << endl;
    cout << "4 - Convert kts to kmh" << endl;
    cout << "5 - Convert C to F" << endl;
    cout << "6 - Convert F to C" << endl;
    cout << "7 - Convert L to G/US" << endl;
    cout << "8 - Convert G/US to L" << endl;
    cout << "[Select number from 1 to 8] : " << endl;
#pragma endregion menu
    char _input; 
    cin >> _input;
    if (_input == '1')
        cout << GetMeterFromFeet(GetValueToConvert());
    else if (_input == '2')
        cout << GetFeetFromMeter(GetValueToConvert());
    else if (_input == '3')
        cout << GetKtsFromKmh(GetValueToConvert());
    else if (_input == '4')
        cout << GetKmhFromKts(GetValueToConvert());
    else if (_input == '5')
        cout << GetFahrFromC(GetValueToConvert());
    else if (_input == '6')
        cout << GetCelciusFromF(GetValueToConvert());
    else if (_input == '7')
        cout << GetUSGalFromL(GetValueToConvert());
    else if (_input == '8')
        cout << GetLFromUSGal(GetValueToConvert());
    else
    {
        system("CLS");
        ConverterMenu();
    }

}
int main()
{
    ConverterMenu();
}




