#pragma once

#define ENUM(name,... ) \
	 enum class name(__VA_ARGS__) \
	 const char* operator*()\
	 { \
		typedef(__VA_ARGS__) \
	 };
