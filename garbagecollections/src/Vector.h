#pragma once
#include "EntityCollection.h"
#include "VectorIterator.h"

namespace HTM
{
	template<class CollType>
	class Vector : public EntityCollection<CollType>
	{
		CollType* _V_Storage;
		size_t _V_Capasity;

	public:
		using VType = CollType;
		using Iterator = VectorIterator< Vector<CollType> >;

		Vector();
		Vector(size_t Size);
		Vector(const std::initializer_list<CollType>& list);
		~Vector();

		bool Empty() const
		{
			return this->_EC_size == 0;
		}

		CollType& operator[](size_t index)
		{
			CheckIndex(index, this->_EC_size);
			return this->_V_Storage[index];
		}

		const CollType& operator[](size_t index) const
		{
			CheckIndex(index, this->_EC_size);
			return this->_V_Storage[index];
		}

		//for iterator:
		Iterator begin();
		Iterator end();

		/// vec methods
		void PushBack(const CollType& value)
		{
			if (this->_EC_size < _V_Capasity)
			{
				this->_V_Storage[this->_EC_size++] = value;
			}
			else
			{
				// replace vector:

			}
		}
		CollType& PopBack()
		{
			if (this->_EC_size > 0)
			{
				return _V_Storage[this->_EC_size--];
			}
			else
			{
				//chech if vectror isEmpty:
				TS_Error("Vector::PopBack when Size <= 0");
			}
		}
	};

	/// 
}