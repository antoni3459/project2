#include <iostream>
#include "Quaternion.h"

//template<typename T>
//void Display(const std::string _title, T _methods)
//{
//    std::string _barrier = "========================";
//    std::cout << _barrier << std::endl;
//    std::cout << _title << std::endl;
//    std::cout << _methods << std::endl;
//    std::cout << _barrier << std::endl;
//}

int main()
{
	
	Quaternion quat = Quaternion(50, 25, 80, 125);
	Quaternion quat1 = Quaternion(80, 30, 25, 40);
    std::cout<<Quaternion::Conjugate(quat).ToString()<<std::endl;
    std::cout<<Quaternion::Angle(quat, quat1).ToString()<<std::endl;

}
