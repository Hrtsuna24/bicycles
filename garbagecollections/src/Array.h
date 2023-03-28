#pragma once
#include "EntityCollection.h"
#include "ArrayIterator.h"

namespace HTM
{
	template<typename CollType, size_t S>
	class Array : private EntityCollection<CollType>
	{
		CollType _AR_storage[S];

	public:
		using VType = CollType;
		using Iterator = ArrayIterator< Array<CollType, S> >;
		//////////////////////

		virtual constexpr size_t Size() const override;

		
		Array(const Array<CollType, S>& arr);
		Array(const std::initializer_list<CollType>& list);
		~Array() {};

		virtual CollType& operator[](size_t index) override;
		virtual const CollType& operator[](size_t index) const override;

		//for iterator:
		/*virtual Iterator begin();
		virtual Iterator end();*/
	};
//
//		///----------------------------
//	
//	public:
//		using Iterator = ArrayIterator< Array<CollType, S> >*;
//		/////
//		Array();
//		Array(const std::initializer_list<CollType>& List);
//		~Array();
//
//		////using in func like memset
//		//PtrType Data();
//		//const PtrType Data() const;
//
//		constexpr size_t Size() const override;
//		CollType& operator[](size_t index) override
//		{
//			CheckIndex(index, S);
//			return this->_AR_storage[index];
//		}
//		const CollType& operator[](size_t index) const override
//		{
//			CheckIndex(index, S);
//			return (_AR_storage[index]);
//		}
//
//		virtual Iterator begin() override;
//		{
//			return EntityCollection&((Array&)_AR_storage[0]);
//		}
//
//		//virtual Iterator* end() override;
//		/*{
//			return Iterator((&_AR_storage[S]));
//		}*/
//	};
//
//
//
//	template<typename CollType, size_t S>
//	inline Array<CollType, S>::Array()
//	{
//		TS_LOG("Array()");
//	}
//
//	template<typename CollType, size_t S>
//	inline Array<CollType, S>::Array(const std::initializer_list<CollType>& List)
//	{
//		TS_LOG("Array(List)");
//		CheckIndex(S - 1, List.size());
//		size_t i = 0;
//		for (const auto& elem : List)
//		{
//			this->_AR_storage[i] = elem;
//			i++;
//		}
//	}
//
//	template<typename CollType, size_t S>
//	inline Array<CollType, S>::~Array()
//	{
//		TS_LOG("~Array()");
//	}
//
//	template<typename CollType, size_t S>
//	inline constexpr size_t Array<CollType, S>::Size() const
//	{
//		return size_t(S);
//	}
}