#pragma once

#ifdef _WIN32||_WIN64
__interface IFly
{
public:
	void Fly();
	float speed();
};

#elif __APPLE__ || __linux

class IFly
{
public:
	virtual ~IFly() = default;
	virtual void Ifly() = 0;
	virtual float speed() = 0;

};
#endif
