#pragma once
#include "EntityCollection.h"
#include "ArrayIterator.h"

namespace HTM
{
	template<typename CollType, size_t S>
	class Array : private EntityCollection<CollType>
	{
		CollType _AR_storage[S];

	public:
		using VType = CollType;
		using Iterator = ArrayIterator< Array<CollType, S> >;
		//////////////////////

		virtual constexpr size_t Size() const override;

		Array();
		Array(const Array<CollType, S>& arr);
		Array(const std::initializer_list<CollType>& list);
		~Array();

		virtual CollType& operator[](size_t index) override;
		virtual const CollType& operator[](size_t index) const override;

		//for iterator:
		 Iterator begin() ;
		 Iterator end() ;
	};
}