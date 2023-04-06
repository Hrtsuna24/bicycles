#include "Preproc.h"
#include "vEctOr.h"

namespace HTM
{
	template<typename CollType>
	VectorIterator< vEctOr<CollType> > vEctOr<CollType>::begin()
	{
		return Iterator(this->_V_Storage);
	}

	template<typename CollType>
	VectorIterator< vEctOr<CollType> > vEctOr<CollType>::end()
	{
		return Iterator(_V_Storage + this->_EC_size);
	}


	template<class CollType>
	void vEctOr<CollType>::ReAlloc(size_t NewCap)
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
	inline vEctOr<CollType>::vEctOr()
	{
		this->_EC_size = 0;
		this->_V_Capasity = 1;
		this->_V_Storage = new CollType[this->_V_Capasity];
	}

	template<class CollType>
	inline vEctOr<CollType>::~vEctOr()
	{
		this->Clear();
		::operator delete(this->_V_Storage, sizeof(CollType) * this->_V_Capasity);
	}

	template<typename CollType>
	vEctOr<CollType>::vEctOr(size_t size)
	{
		this->_EC_size = size;
		this->_V_Capasity = this->_EC_size * 1.5;
		this->_V_Storage = new CollType[this->_V_Capasity];
	}
	template<typename CollType>
	vEctOr<CollType>::vEctOr(const std::initializer_list<CollType>& list)
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

	template<class CollType>
	vEctOr<CollType>::vEctOr(const vEctOr& a)
	{
		this->_V_Storage = new CollType[a._V_Capasity];
		for (size_t i = 0; i < a._EC_size; i++)
		{
			_V_Storage[i] = a._V_Storage[i];
		}

		this->_V_Capasity = a._V_Capasity;
		this->_EC_size = a._EC_size;
	}

	template<class CollType>
	vEctOr<CollType>& vEctOr<CollType>::operator=(const vEctOr<CollType>& a)
	{
		// TODO: insert return statement here
		if (this == &a)
		{
			return *this;
		}

		if (a._V_Capasity <= this->_V_Capasity)
		{
			for (size_t i = 0; i < a._EC_size; i++)
			{
				this->_V_Storage[i] = a._V_Storage[i];
			}
			this->_EC_size = a._EC_size;
			return *this;
		}

		CollType* newArr = new CollType[a._V_Capasity];
		for (size_t i = 0; i < a._EC_size; i++)
		{
			newArr[i] = a._V_Storage[i];
		}
		delete[] this->_V_Storage;
		this->_V_Storage = newArr;
		this->_V_Capasity = a._V_Capasity;
		this->_EC_size = a._EC_size;
	}

	template<class CollType>
	vEctOr<CollType>::vEctOr(vEctOr&& a)
	{
		this->_EC_size = a._EC_size;
		this->_V_Storage = a._V_Storage;
		a._V_Storage = nullptr;
		this->_V_Capasity = a._V_Capasity;
	}

	template<class CollType>
	vEctOr<CollType>& vEctOr<CollType>::operator=(vEctOr&& a)
	{
		// TODO: insert return statement here
		delete[]this->_V_Storage;
		this->_V_Storage = a._V_Storage;
		a._V_Storage = nullptr;
		this->_V_Capasity = a._V_Capasity;
		this->_EC_size = a._EC_size;
		return *this;
	}

	template<typename CollType>
	CollType& vEctOr<CollType>::operator[](size_t index)
	{
		CheckIndex(index, this->_EC_size);
		return this->_V_Storage[index];
	}

	 template<typename CollType>
	 const CollType& vEctOr<CollType>:: operator[](size_t index) const
	{
		CheckIndex(index, this->_EC_size);
		return this->_V_Storage[index];
	}

	template<typename CollType>
	void vEctOr<CollType>::PushBack(const CollType& value)
	{
		if (this->_EC_size >= this->_V_Capasity)
		{
			// replace vector:
			this->ReAlloc(this->_V_Capasity * 2);
		}
		new(&(this->_V_Storage[this->_EC_size++])) CollType(value);
	}

	template<class CollType>
	void vEctOr<CollType>::Insert(const CollType& value, size_t position)
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
	void vEctOr<CollType>::Reserve(size_t newSize)
	{
		if (newSize >= this->_V_Capasity) return;
		CollType* newArr = new CollType[newSize];
		for (size_t i = 0; i < this->_EC_size; i++)
		{
			newArr[i] = this->_V_Storage[i];
		}
		delete[]_V_Storage;
		_V_Storage = newArr;
		this->_V_Capasity = newSize;
	}

	template<class CollType>
	void vEctOr<CollType>::Resize(size_t newSize)
	{
		this->Reserve(newSize);
		for (size_t i = this->_EC_size; i < newSize; ++i)
		{
			this->_V_Storage[i].CollType();
		}
	}

	template<class CollType>
	CollType vEctOr<CollType>::Top()
	{
		// TODO: insert return statement here
		return this->operator[](this->_EC_size - 1);
	}

	template<typename CollType>
	void vEctOr<CollType>::PopBack()
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
	void vEctOr<CollType>::Clear()
	{
		for (size_t i = 0; i < this->_EC_size; ++i)
		{
			this->_V_Storage[i].~CollType();
		}
		this->_EC_size = 0;
	}
}