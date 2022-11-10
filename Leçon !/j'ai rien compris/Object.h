#pragma once
#include <string>

enum
{
	Interfarce = 1,
	Class = 2,
	Abstract = 4
};

#define CLASS_INFO(bitmask) \
		int _bitMask=SetBitMask(bitmask);

//#define DECLARE_INFO(parent) \
//private:\
//	int super= SetSuper(super);\
//public:\
//	typedef parent super;\

#define DECLARE_TYPE(parent) \
private:\
typedef parent ParentClassType;\
ParentClassType* parentClass = new ParentClassType();\
public:\
	typedef parent super;\
	virtual ParentClassType* GetParentClass()\
{return parentClass;}

class Object
{
private:
	int bitMask = 0;
public:
	virtual ~Object() = default;
	virtual std::string ToString()const
	{
		return "";
	}
	bool IsInterface() const;
	bool IsClass()const;
	bool IsAbstract() const;
	int SetBitMask(int _mask);
};

