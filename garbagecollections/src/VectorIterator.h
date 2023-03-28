#pragma once
#include "EntityIterator.h"

namespace HTM
{
	template<typename Vector>
	class VectorIterator : public EntityIterator<Vector>
	{
	public:
		using VType = typename Vector::VType;
		using PtrType = const VType*;
		using RefType = const VType&;

		VectorIterator(PtrType m_Ptr) : EntityIterator<Vector>(m_Ptr) { TS_LOG("VectorIterator(PtrType m_Ptr)"); };
		~VectorIterator() { TS_LOG("~VectorIterator()"); }
	private:

	};
}