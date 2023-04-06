#pragma once
#include "EntityCollection.h"
#include "VectorIterator.h"

namespace HTM
{
	template<class CollType >
	class vEctOr : protected EntityCollection<CollType>
	{
		CollType* _V_Storage;
		size_t _V_Capasity, _EC_size;

		void ReAlloc(size_t);
	public:
		using VType = CollType;
		using Iterator = VectorIterator< vEctOr<CollType> >;

		vEctOr();
		explicit vEctOr(size_t Size);
		vEctOr(const std::initializer_list<CollType>& list);
		~vEctOr();

		//Copy & Assignment
		vEctOr(const vEctOr&);
		vEctOr& operator=(const vEctOr&);

		//Move Const & move Assignment
		vEctOr(vEctOr&&);
		vEctOr& operator=(vEctOr&&);

		CollType& operator[](size_t index) override;

		const CollType& operator[](size_t index) const override;

		//for iterator:
		Iterator begin();
		Iterator end();

		/// vec methods
		void PushBack(const CollType& value);
		void Insert(const CollType& value, size_t position);
		void Reserve(size_t newSize);
		void Resize(size_t newSize);
		CollType Capasity() { return this->_V_Capasity; };

		CollType Top();
		void PopBack();
		void Clear() override;
	};
}