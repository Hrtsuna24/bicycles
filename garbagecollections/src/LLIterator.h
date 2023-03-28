#pragma once
#include "EntityIterator.h"


namespace HTM
{
	template<class LinkedList>
	class LLIterator :
		public EntityIterator<LinkedList>
	{
	private:

	public:
		using ValType = typename LinkedList::ValType; //typename Array::VType;
		using PtrType = const ValType*;
		using RefType = const ValType&;

		
	};
}
