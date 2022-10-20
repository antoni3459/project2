#pragma once
#include <initializer_list>
#include <iostream>

template <typename T>
class Reservation
{
#pragma region f/p
private :
	T* reservation = nullptr;
	int count = 0;
	std::string firstname = "";
	std::string lastname = "";
	std::string age = "0";
	bool hotel = true;
	int client=0;
#pragma endregion f/p

#pragma region constructor
public:
	Reservation() = default;
	Reservation(const std::initializer_list <T> & _reservation);
	Reservation(const Reservation* _copy);

#pragma endregion constructor

#pragma region method
public:
	bool Hotel();
	void Affiche();
	void Add();
	void FirstName(const std::string _value);
	void LastName(const std::string _value);
	void Age(const std::string _value);
	void Remove();
	void Display();
	void Clear();
#pragma endregion method
};

template<typename T>
inline Reservation<T>::Reservation(const std::initializer_list<T>& _reservation)
{
	reservation = _reservation;
}

template<typename T>
inline Reservation<T>::Reservation(const Reservation* _copy)
{
	reservation = _copy.reservation;
}



template<typename T>
inline bool Reservation<T>::Hotel()
{
	system("cls");
	std::string _rep = "";
	std::cout << "1: Reservation" << "\n" << "2: return " << std::endl;
	std::cin >> _rep;
	if (_rep == "1")
		return true;
	else
		return false;
}

template<typename T>
inline void Reservation<T>::Affiche()
{
	system("cls");
	std::string _affiche = "";
	std::cout << "1 : Add" << "\n" << "2 : Remove" << "\n" << "3 : Display" << "\n" << "4 : return" << std::endl;
	std::cin >> _affiche;
	if (_affiche == "1")
		Add();
	if (_affiche == "2")
		Remove();
	if (_affiche == "3")
		Display();
	else
		return;
}


template<typename T>
inline void Reservation<T>::Add()
{
	system("cls");
	std::cout << "firstname : ";
	std::cin >> firstname;
	FirstName(firstname);
	std::cout << "lastname : ";
	std::cin >> lastname;
	LastName(lastname);
	std::cout << "age : ";
	std::cin >> age;
	Age(age);1

	Affiche();
}

template<typename T>
inline void Reservation<T>::FirstName(const std::string _value)
{
	T* _reservation = reservation;
	reservation = new std::string[count + 1];
	for (int i = 0; i < count; i++)
	{
		reservation[i] = _reservation[i];
	}
	reservation[count] = _value;
	count++;

}

template<typename T>
inline void Reservation<T>::LastName(const std::string _value)
{
	T* _reservation = reservation;
	reservation = new std::string[count + 1];
	for (int i = 0; i < count; i++)
	{
		reservation[i] = _reservation[i];
	}
	reservation[count] = _value;
	count++;
}

template<typename T>
inline void Reservation<T>::Age(const std::string _value)
{
	T* _reservation = reservation;
	reservation = new std::string[count + 1];
	for (int i = 0; i < count; i++)
	{
		reservation[i] = _reservation[i];
	}
	reservation[count] = _value;
	count++;
}

template<typename T>
inline void Reservation<T>::Remove()
{
	system("cls");
	std::string _rep = "";
	for (int i = 0; i < count; i++)
		std::cout << reservation[i] << std::endl;
	std::cout << "voulais vous suprimer ?" << std::endl;
	std::cin >> _rep;
	if (_rep == "non")
		Affiche();
	else
	{
		Clear();
		Affiche();
	}
}

template<typename T>
inline void Reservation<T>::Display()
{
	system("cls");
	std::string _rep = "";

	for (int i = 0; i < count; i++)
		std::cout << reservation[i] << std::endl;
	std::cout << "return Y/N" << std::endl;
	std::cin >> _rep;
	if (_rep == "y"||_rep =="yes"|| _rep == "oui")
		Affiche();
	if (_rep =="n" || _rep == "non" || _rep == "no")
		Display();
}

template<typename T>
inline void Reservation<T>::Clear()
{
	reservation = nullptr;
	count = 0;
	firstname = "";
	lastname="";
	age="";

}


