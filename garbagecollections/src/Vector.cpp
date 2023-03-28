#include "Preproc.h"
#include "Vector.h"

namespace HTM
{
	template<typename CollType>
	VectorIterator< Vector<CollType> > Vector<CollType>::begin()
	{
		return Iterator(this->_V_Storage);
	}
	template<typename CollType>
	VectorIterator< Vector<CollType> > Vector<CollType>::end()
	{
		return Iterator(_V_Storage + this->_EC_size);
	}


	template<class CollType>
	inline Vector<CollType>::Vector()
	{
		this->_EC_size = 0;
		this->_V_Capasity = 0;
		this->_V_Storage = new CollType[this->_V_Capasity];
	}

	template<class CollType>
	inline Vector<CollType>::~Vector()
	{
		delete[]this->_V_Storage;
	}

	template<typename CollType>
	Vector<CollType>::Vector(size_t size)
	{
		this->_EC_size = size;
		this->_V_Capasity = this->_EC_size * 1.5;
		this->_V_Storage = new CollType[this->_V_Capasity];
	}
	template<typename CollType>
	Vector<CollType>::Vector(const std::initializer_list<CollType>& list)
	{
		Vector(list.size());
		TS_LOG("Vector::Vector(initializer_list):");
		for (size_t i = 0; i < this->_EC_size; ++i)
		{
			this->_V_Storage[i] = *(list.begin() + i);
		}
	}
}