#include "File.h"
#include "Boolean.h"
#include "TestWritter.h"
#include "TextReader.h"
#include "FileStream.h"
#include "FString.h"
#include <fstream>

Core::IO::File::File(const char* _path)
{
	path = _path;
}
Core::IO::File::File(const File& _copy)
{
	path = _copy.path;
}

Core::IO::File::~File()
{
	delete path;
	path = nullptr;
}

Core::IO::FileStream* Core::IO::File::Create(const Core::PrimitiveType::FString& _path)
{
	if (Exist(_path))return new FileStream(_path.ToCstr());
	const char* _pathCstr = _path.ToCstr();
	std::ofstream _stream = std::ofstream(_pathCstr);
	return new FileStream(_pathCstr);
}

Core::PrimitiveType::Boolean Core::IO::File::Exist(const Core::PrimitiveType::FString& _path)
{
	std::ifstream _stream = std::ifstream(_path.ToCstr());
	const bool _result = _stream.good();
	_stream.close();
	return _result;
}