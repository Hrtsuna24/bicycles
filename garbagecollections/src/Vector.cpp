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
	void Vector<CollType>::ReAlloc(size_t NewCap)
	{
		// 1 alloc a new Arr
		//for calling constructors
		CollType* newArr = (CollType*)::operator new(sizeof(CollType) * NewCap);
		//coppy existing block
		// 
		// check what less:
		if (NewCap < this->_EC_size)
		{
			this->_EC_size = NewCap;
		}

		for (size_t i = 0; i < this->_EC_size; i++)
		{
			newArr[i] = this->_V_Storage[i];
		}

		for (size_t i = 0; i < this->_EC_size; ++i)
		{
			this->_V_Storage[i].~CollType();
		}
		//delete existing block
		::operator delete(this->_V_Storage, sizeof(CollType) * NewCap);
		this->_V_Storage = newArr;
		this->_V_Capasity = NewCap;

	}

	template<class CollType>
	inline Vector<CollType>::Vector()
	{
		this->_EC_size = 0;
		this->_V_Capasity = 1;
		this->_V_Storage = new CollType[this->_V_Capasity];
	}

	template<class CollType>
	inline Vector<CollType>::~Vector()
	{
		this->Clear();
		::operator delete(this->_V_Storage, sizeof(CollType) * this->_V_Capasity);
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
		this->_EC_size = list.size();
		this->_V_Capasity = this->_EC_size * 2;
		this->_V_Storage = new CollType[this->_V_Capasity];

		TS_LOG("Vector::Vector(initializer_list):");
		for (size_t i = 0; i < this->_EC_size; ++i)
		{
			this->_V_Storage[i] = *(list.begin() + i);
		}
	}

	template<typename CollType>
	CollType& Vector<CollType>::operator[](size_t index)
	{
		CheckIndex(index, this->_EC_size);
		return this->_V_Storage[index];
	}

	 template<typename CollType>
	 const CollType& Vector<CollType>:: operator[](size_t index) const
	{
		CheckIndex(index, this->_EC_size);
		return this->_V_Storage[index];
	}

	template<typename CollType>
	void Vector<CollType>::PushBack(const CollType& value)
	{
		if (this->_EC_size >= this->_V_Capasity)
		{
			// replace vector:
			this->ReAlloc(this->_V_Capasity * 2);
		}
		new(&(this->_V_Storage[this->_EC_size++])) CollType(value);
	}

	template<class CollType>
	void Vector<CollType>::Insert(const CollType& value, size_t position)
	{
		CollType* newArr;
		if (this->_EC_size >= this->_V_Capasity)
		{
			size_t NewCap = this->_V_Capasity + 10;
			newArr = new CollType[NewCap];

			for (size_t i = 0; i < position; i++)
			{
				newArr[i] = this->_V_Storage[i];
			}
			newArr[position] = value;
			for (size_t i = position+ 1; i < this->_EC_size; i++)
			{
				newArr[i] = this->_V_Storage[i];
			}
			//delete existing block
			delete[]this->_V_Storage;
			this->_V_Storage = newArr;
			this->_V_Capasity = NewCap;
		}
		else
		{

		}
	}

	template<class CollType>
	CollType Vector<CollType>::Top()
	{
		// TODO: insert return statement here
		return this->operator[](this->_EC_size - 1);
	}

	template<typename CollType>
	void Vector<CollType>::PopBack()
	{
		if (this->_EC_size > 0)
		{
			_V_Storage[-1 + this->_EC_size--].~CollType();
		}
		else
		{
			//chech if vectror isEmpty:
			TS_Error("Vector::PopBack when Size <= 0");
		}
	}
	template<class CollType>
	void Vector<CollType>::Clear()
	{
		for (size_t i = 0; i < this->_EC_size; ++i)
		{
			this->_V_Storage[i].~CollType();
		}
		this->_EC_size = 0;
	}
}