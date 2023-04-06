#pragma once

namespace HTM
{
	template<typename CollType>
	class DLL_Node;

	template<typename DoubleLinkedList>
	class DoubleLinkedListIterator;

	template<typename CollType>
	class DoubleLinkedList
	{
	public:
		using VALType = DLL_Node<CollType>;
		using PTRType = VALType*;
		using REFType = VALType&;
		using Iterator = DoubleLinkedListIterator< DoubleLinkedList<CollType> >;

		DoubleLinkedList();
		DoubleLinkedList(DoubleLinkedList& CopiedList);
		~DoubleLinkedList();
		void InsertBack(CollType data);
		void InsertFront(CollType data);
		void Reverse();
		void ReverseAfter(Iterator Node);
		Iterator Find(const CollType& data);
		void Delete(Iterator Node);

		Iterator Begin();
		Iterator End();

		const Iterator CBegin();
		const Iterator CEnd();

		Iterator RBegin();
		Iterator REnd();

		const Iterator CRBegin();
		const Iterator CREnd();

	private:
		PTRType _DLL_head;

		PTRType CreateNode(CollType& data, DLL_Node<CollType>* next = nullptr, DLL_Node<CollType>* prev = nullptr);
		void Clear();
	};

	template<class CollType>
	class DLL_Node
	{
	public:
		CollType _DLL_N_data;
		DLL_Node* _DLL_N_next, *_DLL_N_prev;
		DLL_Node(CollType data, DLL_Node* n, DLL_Node* p) : _DLL_N_data{ data }, _DLL_N_next{ n }, _DLL_N_prev{ p } {};
	};

	//iterator
	template<typename DoubleLinkedList>
	class DoubleLinkedListIterator
	{
	public:
		using VALType = typename DoubleLinkedList::VALType;
		using PTRType = VALType*;
		DoubleLinkedListIterator(PTRType ptr) : _DLLI_prt(ptr) {};
		PTRType operator->() const { return this->_DLLI_prt; };
		//PTRType& operator=(const PTRType& other) { return *this; }

	private:
		PTRType _DLLI_prt;
	};
}

