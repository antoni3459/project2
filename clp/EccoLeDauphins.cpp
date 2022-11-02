#include "EccoLeDauphins.h"
#include "Utils.h"



EccoLeDauphins::~EccoLeDauphins()
{
    Utils::ClearConsole();
}

void EccoLeDauphins::Open()
{
    Ecco();
}

std::string EccoLeDauphins::Ecco()
{
    std::string _ecco = "";
    std::cin >> _ecco;
    std::cout << "\n" << _ecco << std::endl;
    return _ecco;
}

std::string EccoLeDauphins::GetName()
{
    return name;
}
