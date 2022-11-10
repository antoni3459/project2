#include "Time.h"
#include <ctime>
#include <format>
#include <iostream>

#pragma warning(disable: 4996)

void Time::Open()
{
	GetTime();
}

void Time::GetTime()
{
	const time_t _now = time(nullptr);
	const std::tm _tm = *localtime(&_now);
	std::cout << std::format("{:02}/{:02}/{:02} {:02}:{:02}:{:02}", _tm.tm_mday, _tm.tm_mon + 1, _tm.tm_year + 1900, _tm.tm_hour, _tm.tm_min, _tm.tm_sec) << std::endl;
}

std::string Time::Name()
{
	return "Time";
}

std::string Time::Description()
{
	return "Display the system time. ";
}