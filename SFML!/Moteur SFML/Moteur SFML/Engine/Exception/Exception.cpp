#include "Exception.h"
#include <format>

Engine::Exception::Exception(const std::source_location& _source ):self("An exception was occured",_source){ }

Engine::Exception::Exception(const char* _error, const std::source_location& _source) :super()
{
    message = _error;
    PrimaryType::String _className = _source.file_name();
    _className = _className.Replace("class", "");
    _className = _className.SubString(_className.FindLastOf(':') + 1).Trim();
    message.Append(std::format("at line: {}, in function: {}, in class: {}",
        _source.line(),
        _source.function_name(),
        _className).c_str());
}

Engine::Exception::Exception(const Exception& _copy) :super(_copy)
{
    message = _copy.message;
}

Engine::PrimaryType::String Engine::Exception::Error() const
{
    return message;
}

Engine::PrimaryType::String Engine::Exception::ToString() const
{
    return message;
}
