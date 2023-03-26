#pragma once

namespace HTM
{
	template<typename CollType>
	class EntityIterator
	{
	
		using VType = CollType;
		using PType = CollType*;
		using RType = CollType&;

		PType m_ptr;
	public:
		////
		EntityIterator(PType ptr) : m_ptr(ptr){};
		~EntityIterator() {};


		RType operator*() const { return *m_ptr; }
		PType operator->() { return m_ptr; };

		EntityIterator& operator++() { m_ptr++; return *this; }
		EntityIterator operator++(int) { EntityIterator tmp = *this; ++(*this); return tmp; }

		friend bool operator==(const EntityIterator& it1, const EntityIterator& it2) { return it1.m_ptr == it2.m_ptr; }
		friend bool operator!=(const EntityIterator& it1, const EntityIterator& it2) { return !(it1 == it2); }
		
	};
}