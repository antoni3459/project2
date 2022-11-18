#include "FileStream.h"
#include "TestWritter.h"
#include "TextReader.h"
#include "FString.h"
#include "Boolean.h"

Core::IO::FileStream::FileStream(const char* _path)
{
	path = _path;
	reader = new TextReader(_path);
	writter = new TestWritter(_path);
}

Core::IO::FileStream::FileStream(const FileStream& _copy)
{
	path = _copy.path;
		reader = _copy.reader;
		writter = _copy.writter;
}

Core::IO::FileStream::~FileStream()
{
	Close();
	delete reader;
	reader = nullptr;
	delete writter;
	writter = nullptr;
	delete path;
	path = nullptr;
}

 void Core::IO::FileStream::Close()
{
	 if (writter != nullptr)writter->Close();
	 if (reader != nullptr)reader->Close();
}

 Core::IO::TextReader* Core::IO::FileStream::Reader() const
{
	return reader;
}

 Core::IO::TestWritter* Core::IO::FileStream::Writter() const
{
	return writter;
}

 Core::PrimitiveType::FString Core::IO::FileStream::Path() const
{
	return path ;
}

 Core::PrimitiveType::Boolean Core::IO::FileStream::Equals(const FileStream& _other) const
 {
	 return path==_other.path;
 }

 Core::PrimitiveType::FString Core::IO::FileStream::ToString() const
 {
	 return path;
 }

 Core::PrimitiveType::Boolean Core::IO::FileStream::Equals(const Object* _obj) const
 {
	 const FileStream* _other = dynamic_cast<const FileStream*>(_obj);
	 if (_other == nullptr) return false;
	 return Equals(*_other);
 }

  void Core::IO::FileStream::operator<<(const Object* _obj)
 {
	  if (writter == nullptr)return;
	  *writter << _obj;
 }

  void Core::IO::FileStream::operator<<(const Object& _obj)
 {
	 if (writter==nullptr)return;
	 *writter << _obj;
 }
