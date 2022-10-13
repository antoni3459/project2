#include <iostream>
#include<Windows.h>
#include <string>
using namespace std;

const int row = 4, column = 4;
char grid[row][column];

int content[row][column] =
                            {
                                {1, 0, 0, 1},
                                {0, 0, 1, 0},
                                {1, 0, 1, 1},
                                {0, 0, 0, 1}
                            };
//string [] nom
// int[]
//inventaire nom / dammage
//fight 
//inventory [index]={"",""}
string inventory[5][2] =
{
    {"arme 1", "10"},
    {"arme 2", "20"},
    {"arme 3", "30"},
    {"arme 4", "40"},
    {"arme 5", "50"}
};

int exitRow = 3, exitColumn = 3, currentLocationX = 0, currentLocationY = 0;
int playerLife = 100,
maxDamage = 20,
maxBonusLife = 10;

#pragma region methode
void Init();
void ReadTemple();
void SetCursor();
void SetPlayerDammage(int _dmg);
void SetPlayerEffect();
bool LooseGame();
bool WinGame();
void CheckEndGame();
int PickWeapon();
void Fight();
#pragma endregion

/////
/////

void Init()
{
    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < column; x++)
        {
            grid[y][x] = '-';
        }
    }
    grid[exitRow][exitColumn] = 'E';
    grid[currentLocationY][currentLocationX] = 'X';
}
void ReadTemple()
{
    string _tmp;
    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < column; x++)
        {
            _tmp += grid[y][x];
        }
        _tmp += "\n";
    }
    cout << _tmp << endl;
}
void SetCursor()
{
    cout << "Move with z, q, s, d)" << endl;
    char _input;
    bool _isValid = false;
    while (!_isValid)
    {
        cin >> _input;
        _isValid = _input == 's' ||
                   _input == 'z' ||
                   _input == 'q' ||
                   _input == 'd';
    }
    bool _left = _input == 'q',
         _right = _input == 'd',
         _up = _input == 'z',
         _down = _input == 's';
    if (_left)
    {
        currentLocationX--;
        currentLocationX = currentLocationX < 0 ? 0 : currentLocationX;
    }
    else if (_right)
    {
        currentLocationX++;
        currentLocationX = currentLocationX > column - 1 ? column - 1 : currentLocationX;
    }
    else if (_up)
    {
        currentLocationY--;
        currentLocationY = currentLocationY < 0 ? 0 : currentLocationY;
    }
    else if (_down)
    {
        currentLocationY++;
        currentLocationY = currentLocationY > row - 1 ? row - 1 : currentLocationY;
    }
    if (grid[currentLocationY][currentLocationX] != 'E');
        grid[currentLocationY][currentLocationX] = 'X';
    cout << "Cursor location is at : " << currentLocationX << "," << currentLocationY << endl;
}
void SetPlayerDammage(int _dmg)
{
    playerLife -= _dmg;
    playerLife = playerLife < 0 ? 0 : playerLife;
}
void SetPlayerEffect()
{
    bool _damage = content[currentLocationY][currentLocationX];
    playerLife += _damage ? -maxDamage : maxBonusLife;

    playerLife = playerLife < 0 ? 0 :
                  playerLife > 100 ? 100 :
                  playerLife;

    cout << "Player life is : " << playerLife << " PV " << endl;
}
bool LooseGame()
{
    return playerLife == 0;
}
bool WinGame()
{
    return playerLife > 0 && (currentLocationX == exitColumn && currentLocationY == exitRow);
}
void CheckEndGame()
{
    if (LooseGame())
        cout << "You Loose\n";
    else if(WinGame())
        cout << "You Win\n";
}
int PickWeapon()
{
    int _select = 0;
    string _fullID = "";
        for (size_t i = 0;i < 5;i++)
        {
            for (size_t j = 0;j < 5;j++)
            {
                _fullID += " " + inventory[i][j];
            }
            cout << i + 1 << " - " << _fullID << endl;
            _fullID = "";
        }
        while (_select <= 0|| _select >5)
            cin >> _select;
        return stoi(inventory[_select-1][1]);
}
void Fight()
{
    srand((unsigned int)time(NULL));
    int _eDammage = (rand()%(20-11)+10), _eLife = 100;
    while (_eLife > 0 && playerLife > 0)
    {
        //DEbug
        _eLife -= PickWeapon();//weapon
        _eLife = _eLife < 0 ? 0 : _eLife;
        SetPlayerDammage(_eDammage);
        CheckEndGame();
        cout << "e : " << _eLife << "e dammage : "<<_eDammage<<" p : " << playerLife << endl;
    }
}

int main()
{
    Init();
    while (true)
    {
        Fight;
        ReadTemple();
        SetPlayerEffect();
        CheckEndGame();
        SetCursor();
    }
}