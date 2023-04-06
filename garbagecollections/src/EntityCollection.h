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

		//Size for all coll
		virtual size_t Size() const { return this->_EC_size; };
		virtual bool Empty() const { return this->_EC_size == 0; };
		virtual CollType& operator[](size_t index) = 0;
		virtual const CollType& operator[](size_t index) const = 0;
		virtual void Clear() = 0;
		//for iterator:
		/*virtual Iterator begin();
		virtual Iterator end();*/
		
	protected:
		size_t _EC_size = 0;
	};
}