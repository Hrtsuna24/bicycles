#pragma once
#include "EntityCollection.h"

namespace HTM
{
	template<class CollType>
	class Vector : protected EntityCollection<CollType>
	{
		using PtrType = CollType*;
		using RefType = CollType&;
		using iterator = EntityIterator<CollType>;

		PtrType _V_Storage;
		size_t _V_Capasity;

		//
		void ChangeCapasity()
		{
			if (this->_EC_size >= this->_V_Capasity)
			{
				this->_V_Capasity += this->_EC_size >> 1;
			}
		}

	public:
		Vector();
		~Vector();

		size_t Size() const
		{
			return this->_EC_size;
		}

		RefType operator[](size_t index)
		{
			CheckIndex(index, this->_EC_size);
			return this->_V_Storage[index];
		}

		const RefType operator[](size_t index) const
		{
			CheckIndex(index, this->_EC_size);
			return this->_V_Storage[index];
		}

		//for iterator:
		iterator begin()
		{
			return this->_V_Storage;
		}

		iterator end()
		{
			return &(this->_V_Storage[this->_EC_size]);
		}
		/// vec methods
		void PushBack(CollType value)
		{
			//
			this->_V_Storage[this->_EC_size++] = value;
		}
	};

	/// 
	template<class CollType>
	inline Vector<CollType>::Vector() 		
	{
		this->_EC_size = 0;
		this->_V_Capasity = 5;
		this->_V_Storage = new CollType [this->_V_Capasity];
	}

	template<class CollType>
	inline Vector<CollType>::~Vector()
	{
		delete[]this->_V_Storage;
	}
}