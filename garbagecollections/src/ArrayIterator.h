#pragma once
#include "EntityIterator.h"

namespace HTM
{
	template<typename Array>
	class ArrayIterator : public EntityIterator<Array>
	{
	public:
		using VType = typename Array::VType;
		using PtrType = const VType*;
		using RefType = const VType&;

		ArrayIterator(PtrType m_Ptr) : EntityIterator<Array>(m_Ptr) { TS_LOG("ArrayIterator(PtrType m_Ptr)"); };
		~ArrayIterator() { TS_LOG("~ArrayIterator()"); }
	private:
		
	};
}