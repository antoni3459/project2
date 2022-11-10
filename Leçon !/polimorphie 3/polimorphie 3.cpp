// polimorphie 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Entity
{
public:
    virtual ~Entity()  // on met un destructor comme ça il y a qu'un seul Player car il différencie player et entity 
    {

    }
};

class Player : public Entity
{
public :
    Player() = default;
};



int main()
{
    std::vector <Entity*> _entities = std::vector<Entity*>();
    _entities.push_back(new Entity());
    _entities.push_back(new Player());

    for (int i = 0;i < _entities.size();i++)
    {
        Entity* _entity = _entities[i];
        //Player* p = (Player*)_entity ; // il mey 2 fois player 
        Player* p = dynamic_cast<Player*>(_entity);
        if (p != nullptr)
        {
            std::cout << "Is Player" << std::endl;
        }
    }
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
