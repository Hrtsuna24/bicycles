#pragma once
#include "EntityCollection.h"
#include "VectorIterator.h"

namespace HTM
{
	template<class CollType>
	class Vector : public EntityCollection<CollType>
	{
		CollType* _V_Storage;
		size_t _V_Capasity;

		void ReAlloc(size_t);
	public:
		using VType = CollType;
		using Iterator = VectorIterator< Vector<CollType> >;

		Vector();
		Vector(size_t Size);
		Vector(const std::initializer_list<CollType>& list);
		~Vector();

		CollType& operator[](size_t index);

		const CollType& operator[](size_t index) const;

		//for iterator:
		Iterator begin();
		Iterator end();

		/// vec methods
		void PushBack(const CollType& value);
		void Insert(const CollType& value, size_t position);

		CollType Top();
		void PopBack();
		virtual void Clear() override;
	};
}