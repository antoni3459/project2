#pragma once
#include <string>

#define UCLASS()



class Object
{
#pragma region constructor
public:
	Object() = default;
	virtual ~Object() = default;
#pragma endregion constructor
public:
	virtual std::string ToString()const; 
	template <typename T>
	T* GetInterface()const;
};

template<typename T>
inline T* Object::GetInterface() const
{
	return dynamic_cast<T*>(this);
}
