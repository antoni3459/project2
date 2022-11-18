#pragma once
#include <iostream>
#include <string>

class Question
{
private :
	std::string question[2] = { "qu'elle est la date de la 2eme guerre mondiale ?","qu'elle est la date de la 1er guerre mondiale ? " };
	int x = 0;
public:
	Question() = default;
	~Question() = default;

public:
	int GetX();
	std::string GetQuestion();
};

