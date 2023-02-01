#pragma once
#include "IList.h"
#include "../ValueType/ValueType.h"
#include "../../Utils/DebugMacro.h"
#include "../../Utils/Template/Pointer.h"
#include "../Integer/Integer.h"
#include "../../Utils/CorreDefine.h"
#include "../FString/String.h"

namespace Engine::PrimaryType
{
	template<typename InElementType,typename InSizeType =size_t>
	class List : public ValueType, public IList
	{
	private:
		typedef typename std::vector<InElementType>::iterator Iterator;
		typedef typename std::vector<InElementType>::const_iterator ConstIterator;
		typedef std::vector<InElementType> ElementType;
		ElementType data = ElementType();

	public:
		List() = default;
		List(List&&) = default;
		List(const List&) = default;
		List(const std::initializer_list<InElementType>& _tab)
		{
			for (const InElementType& _item : _tab)
				Add(_item);
		}
	public:
		void Add(InElementType _item)
		{
			data.push_back(_item);
		}
		void Remove(InElementType _item)
		{
			const size_t _index = Find(_item);
				if (_index == INDEX_NONE)return;
				RemoveAt(_index);
		}
		void RemoveAt(size_t _index)
		{
			data.erase(data.begin() + _index);
		}
		size_t Find(InElementType _item)
		{
			const size_t _size = data.size();
			for (size_t i = 0;i < _size;++i)
			{
				if (data[i] == _item)return i;
			}
			return INDEX_NONE;
		}

		bool Contains(InElementType _item)
		{
			return Find(_item) != INDEX_NONE;
		}
		Iterator begin() { return data.begin(); }
		ConstIterator begin() const { return data.begin(); }
		Iterator end() { return data.end(); }
		ConstIterator end() const { return data.end(); }
		size_t Count()const override {return data.size(); }

		//String ToString()const override
		//{
		//	const size_t _size = data.size();
		//	for (size_t i = 0;i < _size;++i)
		//	{

		//	}
		//}

		//void SerializeField(std::ostream& _os, const String& _fieldName)override
		//{
		//	_os << "\"" + std::string(_fieldName.ToString().ToCstr()) + "\" : \"" + ToString().ToCstr() + "\"";
		//}

		//void DeSerializeField(std::istream& _os, const PrimaryType::String& _fieldName)override
		//{
		//	std::string _line = "";
		//	while (std::getline(_is, _line))
		//	{
		//		if (_line.find(std::string("\"") + _fieldName.ToCstr() + "\"") != std::string::npos)
		//		{
		//			String _str = _line.c_str();
		//			_str = _str.SubString(_str.FindFirstOf('('), _str.FindFirstOf(')'));
		//			String _x = _str.SubString(_str.FindFirstOf('(') + 1, _str.FindFirstOf(','));
		//			String _y = _str.SubString(_str.FindFirstOf('(') + 1);
		//			*this = Vector2(std::stof(_x.ToCstr()), std::stof(_y.ToCstr()));
		//			break;
		//		}
		//	}
		//}

	public:
		InElementType& operator[](size_t _index)
		{
			return data[_index];
		}
		InElementType operator[](size_t _index)const
		{
			return data[_index];
		}
	};
}


 
  
   
    
     
      
       
        
         
          
            