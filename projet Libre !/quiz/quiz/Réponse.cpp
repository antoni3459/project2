#include "R�ponse.h"
#include "Question.h"

bool R�ponse::GetReponse()
{
    std::string _rep = "";
    int x=0;
    x = Question::GetX();
    std::cin >> _rep;
    if (_rep == reponse[x])// il existe un Split dans hotel qui pourrait r�gler le probl�me de l'espace 
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

int R�ponse::GetScore()
{
    return score;
}
