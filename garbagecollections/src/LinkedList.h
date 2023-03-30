#pragma once
#include "EntityCollection.h"
#include "LLIterator.h"
#include "LLIterator.cpp"

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
		private EntityCollection<CollType>
	{
		Node<CollType>* _LL_Head;

		
		void Link(Node<CollType>* currNode); // connect two nodes
		Node<CollType>* MoveToElemBeforeLast();//return element before the last
	public:
		/// 
		using ValType = Node<CollType>;
		using Iterator = LLIterator< LinkedList<CollType> >;
		/// 
		LinkedList() : _LL_Head(nullptr) {};
		~LinkedList();
		LinkedList(const LinkedList&);

		Node<CollType>* CreateNode(const CollType& data, Node<CollType>* next = nullptr);
		void AddBack(const CollType& data);
		void AddFront(const CollType& data);


		void SubBack();
		void SubFront();

		CollType& Back();
		CollType& Front();
		void InsertAt(size_t posfromHead, const CollType& data);
		void DeleteAt(size_t posfromHead);

		virtual CollType& operator[](size_t index);
		virtual const CollType& operator[](size_t index) const;
		virtual void Clear() override;
		//for iterator:
		Iterator begin();
		Iterator end();

		Iterator Find(const CollType&);

		void Revert();
		void RevertAfter(size_t index);
	};
}

