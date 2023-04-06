#include "Preproc.h"
#include "DoubleLinkedList.h"

namespace HTM
{
	template<class CollType>
	inline DLL_Node<CollType>* DoubleLinkedList<CollType>::CreateNode(CollType& data, DLL_Node<CollType>* next, DLL_Node<CollType>* prev)
	{
		return new DLL_Node<CollType>(data, next, prev);
	}


	template<class CollType>
	inline DoubleLinkedList<CollType>::DoubleLinkedList() :
		_DLL_head(nullptr)
	{
	}

	template<class CollType>
	inline DoubleLinkedList<CollType>::~DoubleLinkedList()
	{
		this->Clear();
	}


	template<class CollType>
	void DoubleLinkedList<CollType>::InsertBack(CollType data)
	{
		if (!this->_DLL_head)
		{
			this->_DLL_head = this->CreateNode(data);
			return;
		}


		while (this->_DLL_head->_DLL_N_next)
		{
			this->_DLL_head = this->_DLL_head->_DLL_N_next;
		}
		this->_DLL_head->_DLL_N_next = this->CreateNode(data, nullptr, this->_DLL_head);

		while (this->_DLL_head->_DLL_N_prev)
		{
			this->_DLL_head = this->_DLL_head->_DLL_N_prev;
		}
	}

	template<class CollType>
	DoubleLinkedListIterator< DoubleLinkedList<CollType> > DoubleLinkedList<CollType>::Find(const CollType& data)
	{
		while (this->_DLL_head && this->_DLL_head->_DLL_N_data != data)
		{
			this->_DLL_head = this->_DLL_head->_DLL_N_next;
		}
		DLL_Node<CollType>* found = this->_DLL_head;
		while (this->_DLL_head->_DLL_N_prev)
		{
			this->_DLL_head = this->_DLL_head->_DLL_N_prev;
		}

		return found;
	}

	template<class CollType>
	void DoubleLinkedList<CollType>::Delete(DoubleLinkedListIterator< DoubleLinkedList<CollType> > Node)
	{
		DLL_Node<CollType>* tmp = this->_DLL_head;
		this->_DLL_head = Node.operator->();
		this->_DLL_head->_DLL_N_prev->_DLL_N_next = this->_DLL_head->_DLL_N_next;
		this->_DLL_head->_DLL_N_prev = this->_DLL_head->_DLL_N_next;
		this->_DLL_head->_DLL_N_data.~CollType();
		delete this->_DLL_head;
		_DLL_head = tmp;

	}

	template<class CollType>
	void DoubleLinkedList<CollType>::Clear()
	{
		DLL_Node<CollType>* NextNode = this->_DLL_head->_DLL_N_next;
		while (this->_DLL_head)
		{
			this->_DLL_head->_DLL_N_data.~CollType();
			delete this->_DLL_head;
			this->_DLL_head = NextNode;
			if (NextNode) { NextNode = NextNode->_DLL_N_next; }
		}
	}
}