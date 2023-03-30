#pragma once
#include "EntityIterator.h"


namespace HTM
{
	template<class LinkedList>
	class LLIterator/* : public EntityIterator<LinkedList>*/
	{
	public:
		using ValType = typename LinkedList::ValType; //typename Array::VType;
		using PtrType = const ValType*;
		using RefType = const ValType&;

		virtual bool operator!=(const LLIterator&b) const
		{ return !(*this == b); };

		virtual LLIterator& operator++() { _LLI_ptr = _LLI_ptr->_N_next; return *this; };
		LLIterator operator++(int) {
			EntityIterator tmp = *this; ++(*this);
			return tmp;
		};
		virtual bool operator==(const LLIterator<LinkedList>& b) const;

		RefType operator*() const { return *_LLI_ptr; };
		PtrType operator->() const { return this->_LLI_ptr; };

		LLIterator(PtrType m_Ptr) : _LLI_ptr(m_Ptr) { TS_LOG("LLIterator(PtrType m_Ptr)"); };
		~LLIterator() { TS_LOG("~EntityIterator()"); }
		virtual RefType operator[](size_t index) { return *(_LLI_ptr + index); };
	
	private:
		PtrType _LLI_ptr;
	};
}
