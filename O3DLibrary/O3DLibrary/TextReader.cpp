#include "TextReader.h"
#include "FString.h"
Core::IO::TextReader::TextReader(const char* _path)
{
	path = _path;
}

Core::IO::TextReader::TextReader(const TextReader& _copy)
{
	path = _copy.path;
	stream = std::ifstream(path);
}

Core::IO::TextReader::TextReader(const PrimitiveType::FString& _path) :TextReader(_path.ToCstr()) { }
