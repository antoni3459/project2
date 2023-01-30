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
	public:
		typedef InElementType ElementType;
		typedef InSizeType SizeType;
		typedef ElementType* Iterator;
		typedef const ElementType* ConstIterator;

	private:
		SizeType arrayNum = 0;
		SizeType arrayMax = 0;
		ElementType* data = nullptr;

	public:
		List()
		{
			arrayNum = 0;
			Resize(100);
		}
		List(const SizeType max)
		{
			arrayNum = 0;
			Resize(max);
		}
		List(const std::initializer_list<ElementType>& _tab)
		{
			arrayNum = 0;
			Resize(_tab.size());
			for (const ElementType& _item : _tab)
				Add(_item);
		}
		List(const List&) = default;
		List(List&&) = delete;
		~List()override
		{
			delete[] data;
			data = nullptr;
		}

	public:
		Iterator begin() { return &data[0]; }
		ConstIterator begin() const { return &data[0]; }
		Iterator end() { return &data[arrayNum]; }
		Iterator end() const { return &data[arrayNum]; }

		void Resize(const SizeType _size)
		{
			const SizeType _result = (SizeType)std::pow(_size, 2) / (_size / 2);
			const SizeType _oldSize = arrayMax;
			arrayMax = _result;
			ElementType* _tmp = data;
			data = new ElementType[arrayMax];
			arrayNum = 0;
			for (SizeType i = 0;i < _result && i != _oldSize && _tmp != nullptr;i++)
			{
				data[i] = _tmp[i];
				++arrayNum;
			}
		}

		void AddRanges(const List& _other)
		{
			if (arrayMax < _other.arrayNum)
				Resize(_other.arrayNum);
			const SizeType _size = static_cast<SizeType>(_other.Count());
			for (SizeType i = 0;i < _size;++i)
				Add(_other[i]);
		}
		void Add(ElementType _item)
		{
			if (arrayNum + 1 > arrayMax)
				Resize(arrayNum + 1);
			data[arrayNum] = _item;
			++arrayNum;
		}
		SizeType Find(const ElementType& _item)const
		{
			for (ConstIterator it = begin();it != end();++it)
			{
				if (*it == _item)
				{
					return static_cast<SizeType>(it - data);
				}
			}
			return INDEX_NONE;
		}

		SizeType FindLast(const ElementType& _item)const
		{
			for (ConstIterator it = end(); it != begin();--it)
			{
				if (*it == _item)
				{
					return static_cast<SizeType>(it - data);
				}
			}
			return INDEX_NONE;
		}

		bool Contains(const ElementType& _item)const
		{
			return Find(_item) != INDEX_NONE;
		}

		void Remove(const ElementType& _item)
		{
			const SizeType _index = Find(_item);
			if (_index == INDEX_NONE)return;
			RemoveAt(_index);
		}
		
		void RemoveAt(SizeType _index)
		{
			ElementType* _newArray = data;
			std::copy(data, data + _index, _newArray);
			std::copy(data + _index + 1, data + arrayNum, _newArray + _index);
			--arrayNum;
		}

	public:
		Integer Count() const override
		{
			return (int)arrayNum;
		}
		String ToString()const override
		{
			String _result = "";
			SizeType _index = 0;
			for (const ElementType& _item : *this)
			{
				_result += ::ToString(_item);
				if (_index <arrayNum-1)
					_result += ",";
				++_index;
			}
			return _result;
		}

		SizeType Max()const
		{
			return data;
		}
		ElementType* Data()
		{
			return data;
		}
		ElementType* Data()const 
		{
			return data;
		}


	public:
		ElementType& operator[](SizeType _index)
		{
			return data[_index];
		}
		ElementType& operator[](SizeType _index)const 
		{
			return data[_index];
		}
		Object& operator=(const Object* _obj)override
		{
			const List* _other = dynamic_cast<const List*>(_obj);
			check((_other != nullptr), "[List] => operator= obj is not List", *this)
				data = _other->data;
			return *this;
		}
		List& operator=(const List&) = default;
		List& operator=(List&&) = default;


};
}