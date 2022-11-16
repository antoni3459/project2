#include "TestWritter.h"
#include "FString.h"
#include "Booleain.h"

Core::IO::TestWritter::TestWritter(const char* _path)
{
	path = _path;
	stream = std::ofstream(_path, std::ios_base::app | std::ios_base::out);
}

Core::IO::TestWritter::TestWritter(const PrimitiveType::FString& _path) :TestWritter(_path.ToCstr()) { }


Core::IO::TestWritter::TestWritter(const TestWritter& _copy)
{
	path = _copy.path;
	stream = std::ofstream(path, std::ios_base::app | std::ios_base::out);

}

Core::PrimitiveType::Boolean Core::IO::TestWritter::IsOpen() const
{
	return stream.is_open();
}

Core::PrimitiveType::Boolean Core::IO::TestWritter::Exsit() const
{
	return stream.good();
}

Core::PrimitiveType::FString Core::IO::TestWritter::Path() const
{
	return path;
}

void Core::IO::TestWritter::Close()
{
	if (stream.is_open())
		stream.close();
}

void Core::IO::TestWritter::Clear()
{
	Close();
	stream = std::ofstream(path, std::ofstream::out | std::ofstream::trunc);

}

void Core::IO::TestWritter::Write(const Object& _obj)
{
	*this << _obj;
}

void Core::IO::TestWritter::Write(const Object* _obj)
{
	*this << _obj;
}

Core::PrimitiveType::FString Core::IO::TestWritter::ToString() const
{
	return path;
}

Core::PrimitiveType::Boolean Core::IO::TestWritter::Equals(const Object* _obj) const
{
	const TestWritter* _other = dynamic_cast<const TestWritter*>(_obj);
	if (_other == nullptr)return false;
	return Equals(*_other);
}

Core::PrimitiveType::Boolean Core::IO::TestWritter::Equals(const TestWritter& _obj) const
{
	return path == _obj.path;
}

void Core::IO::TestWritter::operator<<(const Object& _obj)
{
	if (!IsOpen())return;
	stream << _obj.ToString();
	stream << std::endl;
}

void Core::IO::TestWritter::operator<<(const Object* _obj)
{
	if (!IsOpen())return;
	stream << _obj->ToString();
	stream << std::endl;
}
