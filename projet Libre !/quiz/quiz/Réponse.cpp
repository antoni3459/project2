#include "Réponse.h"
#include "Question.h"

bool Réponse::GetReponse()
{
    std::string _rep = "";
    int x=0;
    x = Question::GetX();
    std::cin >> _rep;
    if (_rep == reponse[x])// il existe un Split dans hotel qui pourrait régler le problème de l'espace 
    {
        std::cout << "c'est gagner" << std::endl;
        score++;
        return true;
    }
    else
    {
        std::cout << "c'est perdu" << std::endl;
        score--;
        return false;
    }

}

int Réponse::GetScore()
{
    return score;
}
