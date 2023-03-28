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

	private:

	};
	//template<typename Array>
	//class ArrayIterator : public EntityIterator<Array>
	//{
	////	EntityIterator-> class PType m_ptr;

	//public:
	//	//declare own "words" for fucking lardge types" O_o
	//	/*using VType = typename Array::CollType;
	//	using PtrType = VType*;
	//	using RefType = VType&;*/
	////	////
	//	ArrayIterator(PType ptr) : EntityIterator(ptr) {};
	//	virtual ~ArrayIterator() {};
	//};
}