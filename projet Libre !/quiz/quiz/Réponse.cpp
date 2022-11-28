#include "Réponse.h"
#include "Question.h"
<<<<<<< Updated upstream

bool Réponse::GetReponse()
{
    std::string _rep = "";
    int x=0;
    x = Question::GetX();
    std::cin >> _rep;
    if (_rep == reponse[x])
    {
        std::cout << "c'est gagner" << std::endl;
        score++;
=======
#include <iostream>

bool Réponse::GetReponse()
{
    int x = Question::GetX();
    std::string _rep;
    std::cin >> _rep;
    if (_rep == reponse[x])
    {
        std::cout << "win";
        count++;
>>>>>>> Stashed changes
        return true;
    }
    else
    {
<<<<<<< Updated upstream
        std::cout << "c'est perdu" << std::endl;
        score--;
        return false;
    }

}

int Réponse::GetScore()
{
    return score;
=======
        std::cout << "perdu";
        count--;
        return false;
    }
>>>>>>> Stashed changes
}
