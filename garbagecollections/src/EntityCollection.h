#pragma once
#include "EntityIterator.h"

namespace HTM
{
	template<typename CollType>
	class EntityCollection;

	/*template<typename CollType>
	using PtrType = EntityCollection<CollType>::CollType*;*/

	template<typename CollType>
	class EntityCollection
	{
	public:
		// for better understanding types:
		
		using PtrType = CollType*;
		using RefType = CollType&;
		using iterator = EntityIterator<CollType>;

		///////

		EntityCollection();
		virtual ~EntityCollection();

		//Size for all coll
		virtual size_t Size() const = 0;
		virtual RefType operator[](size_t index) = 0;
		virtual const RefType operator[](size_t index) const = 0;

		//for iterator:
		virtual iterator begin() = 0;
		virtual iterator end() = 0;
	protected:
		size_t _EC_size;
	private:
		
	};

}

template<typename CollType>
inline HTM::EntityCollection<CollType>::EntityCollection()
{
	TS_LOG("EntityCollection()");
}

template<typename CollType>
inline HTM::EntityCollection<CollType>::~EntityCollection()
{
	TS_LOG("~EntityCollection()");
}