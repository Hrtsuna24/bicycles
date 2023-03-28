#pragma once
#include "EntityCollection.h"
#include "LLIterator.h"

namespace HTM
{
	template<class CollType>
	class Node
	{
	public:
		Node* _N_next = nullptr;
		CollType _N_data;
	};

	template<class CollType>
	class LinkedList :
		public EntityCollection<CollType>
	{
		Node<CollType> _LL_Node;

	public:
		/// 
		using ValType = CollType;
		using Iterator = LLIterator< LinkedList<CollType> >;
		/// 
		LinkedList();
		~LinkedList();
		LinkedList(const LinkedList&);

		void Add(const LinkedList&);
	};
}

