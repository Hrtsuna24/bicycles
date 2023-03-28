#include "Preproc.h"
#include "Array.h"

namespace HTM
{
	template<typename CollType, size_t S>
	constexpr size_t Array<CollType, S>::Size() const
	{
		return S;
	}
	
	template<typename CollType, size_t S>
	Array<CollType, S>::Array(const Array<CollType, S>& arr)
	{
		if (this->Size() == arr.Size())
		{
			for(size_t i = 0; i < S; ++i)
			{ 
				this->_AR_storage[i] = arr._AR_storage[i];
			}
		}
		else
		{
			TS_WAR("Array::Array(const Array&):");
		}
	}


	
	template<typename CollType, size_t S>
	Array<CollType, S>::Array(const std::initializer_list<CollType>& list)
	{
		if (S == list.size())
		{
			for (size_t i = 0; i < S; ++i)
			{
				this->_AR_storage[i] = *(list.begin() + i);
			}
		}
		else
		{
			TS_WAR("Array::Array(const initializer_list&):");
		}
	}
	template<typename CollType, size_t S>
	CollType& Array<CollType, S>::operator[](size_t index) 
	{
		return this->_AR_storage[index];
	}
	template<typename CollType, size_t S>
	const CollType& Array<CollType, S>::operator[](size_t index) const 
	{
		return this->_AR_storage[index];
	}


	/*template<typename CollType, size_t S>
	ArrayIterator< Array<CollType, S> > Array<CollType, S>::begin()
	{
		return Iterator(this->_AR_storage);
	}
	template<typename CollType, size_t S>
	ArrayIterator< Array<CollType, S> > Array<CollType, S>::end()
	{
		return Iterator(this->_AR_storage + S);
	}*/
}