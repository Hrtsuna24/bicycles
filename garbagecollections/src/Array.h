#pragma once
#include "EntityCollection.h"
//#include "EntityIterator.h"

namespace HTM
{
	template<typename CollType, size_t S>
	class Array : private EntityCollection<CollType>
	{
		CollType _AR_storage[S];

		///----------------------------
	protected:

	public:
		/*using ARefType  = EntityCollection<CollType>::RefType;
		using APtrType  = EntityCollection<CollType>::PtrType;
		using Aiterator = EntityCollection<CollType>::iterator;*/

		/////
		Array();
		Array(const std::initializer_list<CollType>& List);
		~Array();

		////using in func like memset
		//PtrType Data();
		//const PtrType Data() const;

		constexpr size_t Size() const override;
		EntityCollection<CollType>::RefType operator[](size_t index) override
		{
			CheckIndex(index, S);
			return this->_AR_storage[index];
		}
		const EntityCollection<CollType>::RefType operator[](size_t index) const override
		{
			CheckIndex(index, S);
			return EntityCollection<CollType>::RefType(this->_AR_storage[index]);
		}
		EntityCollection<CollType>::iterator begin() override
		{
			return this->_AR_storage;
		}

		EntityCollection<CollType>::iterator end() override
		{
			return &(_AR_storage[S]);
		}
	};



	template<typename CollType, size_t S>
	inline Array<CollType, S>::Array()
	{
		TS_LOG("Array()");
	}

	template<typename CollType, size_t S>
	inline Array<CollType, S>::Array(const std::initializer_list<CollType>& List)
	{
		TS_LOG("Array(List)");
		CheckIndex(S - 1, List.size());
		size_t i = 0;
		for (const auto& elem : List)
		{
			this->_AR_storage[i] = elem;
			i++;
		}
	}

	template<typename CollType, size_t S>
	inline Array<CollType, S>::~Array()
	{
		TS_LOG("~Array()");
	}

	template<typename CollType, size_t S>
	inline constexpr size_t Array<CollType, S>::Size() const
	{
		return size_t(S);
	}
}