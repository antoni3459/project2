#pragma once
#include "IList.h"
#include "../ValueType/ValueType.h"
#include "../../Utils/DebugMacro.h"
#include "../../Utils/Template/Pointer.h"
#include "../Integer/Integer.h"
#include "../../Utils/CorreDefine.h"
#include "../FString/String.h"
#include "../../Utils/Template/Template.h"

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

		//}

		void SerializeField(std::ostream& _os, const String& _fieldName, int _index) override
		{
			if (String::IsNullOrEmpty(_fieldName))
				_os << "[\n";
			else
				_os << "\"" + std::string(_fieldName.ToCstr()) + "\" : ";


			if constexpr (IsPointer<InElementType>::Value)
				_os << "\"" << data[0]->ClassName().ToCstr() << "\"";
			else
				_os << "\"" << data[0].ClassName().ToCstr() << "\"";

			_os << " [\n";


			const size_t _size = data.size();
			for (size_t i = 0; i < _size; ++i)
			{
				_os << std::string(_index, '\t') << "\t\t";
				if constexpr (IsPointer<InElementType>::Value)
				{
					if (data[i]->IsClass())
						data[i]->Serialize(_os);
					else 
						data[i]->SerializeField(_os, "", _index);
				}
				else
				{
					if (data[i].IsClass())
						data[i].Serialize(_os);
					else 
						data[i].SerializeField(_os, "", _index);
				}
				if (i < _size - 1)
					_os << ",";
				_os << "\n";
			}
			_os << std::string(_index, '\t') << "]";
		}

		void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName)override
		{
			bool _inList = false;
			std::string _line = "";
			while (std::getline(_is, _line))
			{

				if (_line.find(std::string("\"") + _fieldName.ToCstr() + "\"") != std::string::npos)
				{
					_inList = true;
				}
				if (_inList)
				{

				}
			}
		}

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