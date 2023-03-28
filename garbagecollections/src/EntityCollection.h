#pragma once
#include "EntityIterator.h"

namespace HTM
{
	template<typename CollType>
	class EntityCollection
	{
	public:
		// declare smaller type for iterator
		using VType = CollType;
		using Iterator = EntityIterator< EntityCollection<CollType> >;
		///////

		EntityCollection(); // def in 37line
		virtual ~EntityCollection(); // def in 42line

		//Size for all coll
		virtual size_t Size() const { return this->_EC_size; };
		virtual CollType& operator[](size_t index) = 0;
		virtual const CollType& operator[](size_t index) const = 0;

		//for iterator:
		/*virtual Iterator begin();
		virtual Iterator end();*/
		
	protected:
		size_t _EC_size;
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