#pragma once
#include <iostream>
#include <string>

class Question
{
private :
<<<<<<< Updated upstream
	const int max = 6;
	std::string question[6] = { "qu'elle est la date de la 2eme guerre mondiale ?",
		"qu'elle est la date de la 1er guerre mondiale ? ",
		"Quelle est la date du debarquement en Normandie ",
		"Quelle est la l'annee de l'entrer en guerre des USA",
		"Quelle est le generale de toutes les force allier dans le secteur Européen",
		"Quelle est l'annee de la l'armistice de la France"};
	static inline int x = 0;
	
=======
	std::string question[2] = { "qu'elle est la date de la 2eme guerre mondiale ?","qu'elle est la date de la 1er guerre mondiale ? " };
	static inline int x ;
>>>>>>> Stashed changes
public:
	Question() = default;
	~Question() = default;

public:
<<<<<<< Updated upstream
	 std::string GetQuestion();
	static int GetX();
=======
	std::string GetQuestion();
	static int GetX();

>>>>>>> Stashed changes

};

