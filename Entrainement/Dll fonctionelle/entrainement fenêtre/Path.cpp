#include "Path.h"
#include "FString.h"
#include "Interger.h"

Core::PrimitiveType::FString Core::IO::Path::GetPath(const PrimitiveType::FString& _path)
{
	return _path.Replace('\\', DirectorySeparator);
}
Core::PrimitiveType::FString Core::IO::Path::GetParent(const PrimitiveType::FString& _path)
{
	PrimitiveType::FString _p = GetPath(_path);
	const int _index = _path.LastIndexOf(DirectorySeparator);
	return _path.SubString(0, _index);
}
Core::PrimitiveType::FString Core::IO::Path::Combine(const std::initializer_list < PrimitiveType::FString>& _path)
{
	PrimitiveType::FString _result = "";
	const size_t _size = _path.size();
	int _index = 0;
	for (const PrimitiveType::FString& _item : _path)
	{
		_result += _item;
		if (_index < _size - 1)
			_result.Append(DirectorySeparator);
		_index++;
	}
	return GetParent(_result);
}