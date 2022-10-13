// 2DTab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 
const int sizeTab = 4; 
int oneTab[sizeTab] = { 1,2,3,4 }; //one
int twoTab[sizeTab][sizeTab] = {
					  {1,2,3,4},//0 -> [0,1,2,3]
					  {4,5,6,7}, //1 -> [0,1,2,3]
					  {8,9,10,11},//2 -> [0,1,2,3]
					  {12,13,14,15}//3 -> [0,1,2,3]
				   }; //4x4

int a[1][2] = {
				{0,1}
			  };
//a[] = {0,1} 
int b[2][2] = {
				{0,1},
				{0,1}
			  };

//Matrix4x4
int matrixRotationIdentity[4][4] = 
								  {
								  	{1,0,0,0},
								  	{0,1,0,0},
								  	{0,0,1,0},
								  	{0,0,0,1}
								  };
std::string students[5][3] = 
							{
								{"Jean", "Student", "Prog"},
								{"John", "Doe", "Prog"},
								{"Jean", "Student", "Cine"},
								{"John", "Doe", "Anim"},
								{"Jean", "Student", "Prog"}
							};

void Example(int _tab[sizeTab][sizeTab])
{

}

int main()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			std::string _student = "";
			_student += " " + students[y][x];
			std::cout << _student;
		}
		std::cout << std::endl;
	}
}
