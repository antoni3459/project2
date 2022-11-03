#include "EccoLeDauphins.h"
#include "Utils.h"


void Echo::Open()
{
    Ecco();
}

std::string Echo ::Ecco()
{
    std::string _ecco = "";
    std::cin >> _ecco;
    std::cout << "\n" << _ecco << std::endl;
    return _ecco;
}
std::string Echo::Name()
{
    return "echo";
}
std::string Echo::Description()
{
    return "Display messagers, or turns command-echoing on or off ";
}


