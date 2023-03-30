#include "Preproc.h"
#include "LinkedList.h"

namespace HTM
{
	template<class CollType>
	void LinkedList<CollType>::Link(Node<CollType>* currNode)
	{
		this->_LL_Tail->_N_next = CreateNode(currNode->_N_data);
		this->_LL_Tail = this->_LL_Tail->_N_next;
	}


	template<class CollType>
	LinkedList<CollType>::~LinkedList()
	{
		Clear();
	}


	template<class CollType>
	LinkedList<CollType>::LinkedList(const LinkedList& other)
	{
		Node<CollType>* currNode;
		currNode = other._LL_Head;
		if (currNode) // set head and tail
		{
			this->_LL_Head = CreateNode(currNode->_N_data);
			this->_LL_Tail = this->_LL_Head;
			currNode = currNode->_N_next;
		}
		while (currNode) //build list till could
		{
			this->Link(currNode);
			currNode = currNode->_N_next;
		}
	}


	template<class CollType>
	Node<CollType>* LinkedList<CollType>::CreateNode(const CollType& data, Node<CollType>* next)
	{
		Node<CollType>* tmpnode = new Node<CollType>;
		tmpnode->_N_data = data;
		tmpnode->_N_next = next;
		return tmpnode;
	}


	template<class CollType>
	void LinkedList<CollType>::AddBack(const CollType& data)
	{
		if (!this->_LL_Head)
		{
			this->_LL_Head = CreateNode(data);
			return;
		}
		else if (!this->_LL_Head->_N_next)
		{
			this->_LL_Head->_N_next = CreateNode(data);
			return;
		}
		else
		{
			MoveToElemBeforeLast()->_N_next->_N_next = CreateNode(data);
		}
	}

	template<class CollType>
	void LinkedList<CollType>::AddFront(const CollType& data)
	{
		// create Node
		if (!this->_LL_Head) // if curr list is Empty
		{
			this->_LL_Head = CreateNode(data);
			this->_LL_Tail = this->_LL_Head; // set h and t to curr node(one)
		}
		else //if list has one or more nodes
		{
			//create node and link it to the start of the list
			Node<CollType>* tmp = this->_LL_Head;
			this->_LL_Head = CreateNode(data);
			// end H->next must have addres of prev start
			this->_LL_Head->_N_next = tmp;
		}
	}

	template<class CollType>
	void LinkedList<CollType>::SubBack()
	{
		Node<CollType>* LastElem;
		// go to the elem before last via Mover ptr
		if (!this->_LL_Head)
		{
			TS_Error("LinkedList::SubBack - delete from empry list");
			return;
		}
		if (!this->_LL_Head->_N_next)
		{
			LastElem = this->_LL_Head;
			LastElem->_N_data.~CollType();
			delete LastElem;
			return;
		}
		Node<CollType>*Mover = this->MoveToElemBeforeLast();
		//set pointer to the last elem
		LastElem = Mover->_N_next;
		// Last elem point to the null
		Mover->_N_next = nullptr;
		//delete the last node
		LastElem->_N_data.~CollType();
		delete LastElem;
	}

	template<class CollType>
	void LinkedList<CollType>::SubFront()
	{
		// check if empty
		if (!this->_LL_Head)
		{
			TS_Error("LinkedList::SubFront - delete from empry list");
			return;
		}
		if (!this->_LL_Head->_N_next)
		{
			this->_LL_Head->_N_data.~CollType();
			delete this->_LL_Head;
			return;
		}
		Node<CollType>* SecondToFirstElem = this->_LL_Head->_N_next;
		this->_LL_Head->_N_data.~CollType();
		delete this->_LL_Head;
		this->_LL_Head = SecondToFirstElem;
	}


	template<class CollType>
	CollType& LinkedList<CollType>::Front()
	{
		return this->_LL_Head->_N_data;
	}

	template<class CollType>
	void LinkedList<CollType>::InsertAt(size_t posfromHead, const CollType& data)
	{
		Node<CollType>* Mover = this->_LL_Head;
		size_t i = 1; // 1 - head, 2 - to stop on elem before posfromHead
		while (i < posfromHead) {
			if (Mover->_N_next)
			{
				Mover = Mover->_N_next;
				i++;
			}
			else
			{
				TS_Error("LinkedList::InsertAt::Node[posfromHead] does not exist");
			}
		}
		Mover->_N_next = CreateNode(data, Mover->_N_next);
	}

	template<class CollType>
	void LinkedList<CollType>::DeleteAt(size_t posfromHead)
	{
		if (!posfromHead)
		{
			this->SubFront();
		}
		if (!this->_LL_Head) {
			TS_Error("LinkedList::DeleteAt - try delete elem in empty list");
			return;
		}
		Node<CollType>* Mover = this->_LL_Head;
		size_t i = 1;
		while (Mover && (i++ < posfromHead))
		{
			Mover = Mover->_N_next;
		}
		Mover->_N_next->_N_data.~CollType();
		delete Mover->_N_next;
		Mover->_N_next = nullptr;
	}

	template<class CollType>
	CollType& LinkedList<CollType>::Back()
	{
		return this->_LL_Tail->_N_data;
	}

	template<class CollType>
	CollType& LinkedList<CollType>::operator[](size_t index)
	{
		// TODO: insert return statement here
		
		return this->_LL_Head->_N_data;
	}
	template<class CollType>
	const CollType& LinkedList<CollType>::operator[](size_t index) const
	{
		// TODO: insert return statement here
		return this->_LL_Head->_N_data;
		
	}
	template<class CollType>
	void LinkedList<CollType>::Clear() //Delete list
	{
		Node<CollType>* Curr, * Next;;
		Curr = this->_LL_Head;
		while (Curr)
		{
			Next = Curr->_N_next;
			Curr->_N_data.~CollType();
			delete Curr;
			Curr = Next;
		}
	}
	template<class CollType>
	LLIterator< LinkedList<CollType> > LinkedList<CollType>::begin()
	{
		return LLIterator<LinkedList<CollType> >(this->_LL_Head);
	}

	template<class CollType>
	LLIterator< LinkedList<CollType> > LinkedList<CollType>::end()
	{
		return nullptr;
	}

	template<class CollType>
	LLIterator< LinkedList<CollType> > LinkedList<CollType>::Find(const CollType& ToFind)
	{
		Node<CollType>* Mover = this->_LL_Head;
		while (Mover->_N_data != ToFind)
		{
			Mover = Mover->_N_next;
			if (!Mover)
			{
				break;
			}
		}
		return Mover;
	}
	template<class CollType>
	void LinkedList<CollType>::Revert()
	{
		Node<CollType>* PrevNode = nullptr; //prev node of firstToLast elem
		Node<CollType>* NextNode; //second elem
		while (this->_LL_Head)
		{
			NextNode = this->_LL_Head->_N_next;
			this->_LL_Head->_N_next = PrevNode;
			PrevNode = this->_LL_Head;
			this->_LL_Head = NextNode;
		}
		this->_LL_Head = this->_LL_Tail;

		//set tail to the new end of the list
		while (this->_LL_Tail->_N_next)
		{
			this->_LL_Tail = this->_LL_Tail->_N_next;
		}
	}
	template<class CollType>
	void LinkedList<CollType>::RevertAfter(size_t index)
	{
		while (index)
		{
			if (!this->_LL_Head && (index))
			{

			}
			index--;
		}
	}

	template<class CollType>
	Node<CollType>* LinkedList<CollType>::MoveToElemBeforeLast()
	{
		// go to the elem before last via Mover ptr
		Node<CollType>* Mover = this->_LL_Head;
		if (!(Mover && Mover->_N_next))
		{
			return nullptr;
		}
		else
		{
			while (Mover->_N_next->_N_next)
			{
				Mover = Mover->_N_next;
			}
		}
		return Mover;
	}
}