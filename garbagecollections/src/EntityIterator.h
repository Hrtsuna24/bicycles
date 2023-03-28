#pragma once

namespace HTM
{
	template<typename EntityCollection>
	class EntityIterator
	{

	public:
		using VType = typename EntityCollection::VType;
		using PtrType = const VType*;
		using RefType = const VType&;

		virtual bool operator==(const EntityIterator* b) = 0;
		virtual bool operator!=(const EntityIterator* b) = 0;
		EntityIterator& operator++() { ++_m_Ptr; return *this; };
		EntityIterator operator++(int) {
			EntityIterator tmp = *this; ++(*this);
			return tmp;
		};

		RefType operator*() const { return *_m_Ptr; };
		PtrType operator->() const { return this->_m_Ptr; };

		EntityIterator(PtrType m_Ptr) : _m_Ptr(m_Ptr) {};
		~EntityIterator() {}

		RefType operator[](size_t index) { return *(_m_Ptr + index); };

	private:
		PtrType _m_Ptr;
	};
}