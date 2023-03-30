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
		this->_EC_size = other._EC_size;
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
		// create Node
		if (!this->_LL_Head) // if curr list is Empty
		{
			this->_LL_Head = CreateNode(data);
			this->_LL_Tail = this->_LL_Head; // set h and t to curr node(one)
		}
		else //if list has one or more nodes
		{
			//create node and link it to the end of the list
			this->_LL_Tail->_N_next = CreateNode(data);
			// end t must have addres of last elem
			this->_LL_Tail = this->_LL_Tail->_N_next;
		}
		this->_EC_size++;
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
		this->_EC_size++;
	}

	template<class CollType>
	void LinkedList<CollType>::SubBack()
	{
		// check if empty
		CheckIndex(0, this->_EC_size);

		//delete the last node
		this->_LL_Tail->_N_data.~CollType();
		delete this->_LL_Tail;
		this->_EC_size--;
		// end t must have addres of last elem
		this->_LL_Tail = this->_LL_Head;
		size_t i = 1;
		while (i < this->_EC_size)
		{
			this->_LL_Tail = this->_LL_Tail->_N_next;
			i++;
		}
		this->_LL_Tail->_N_next = nullptr;
	}

	template<class CollType>
	void LinkedList<CollType>::SubFront()
	{
		// check if empty
		CheckIndex(0, this->_EC_size);


		Node<CollType>* SecondToFirstElem = this->_LL_Head->_N_next;
		this->_LL_Head->_N_data.~CollType();
		delete this->_LL_Head;
		this->_LL_Head = SecondToFirstElem;
		this->_EC_size--;
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
		this->_EC_size++;
	}

	template<class CollType>
	void LinkedList<CollType>::DeleteAt(size_t posfromHead)
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
		//Mover is set on elem before deleted
		Node<CollType>* ElemToDelete = Mover->_N_next;
		Mover->_N_next = ElemToDelete->_N_next; // set next addres on elem after deleted
		ElemToDelete->_N_data.~CollType();
		delete ElemToDelete;
		this->_EC_size--;
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
		if (index >= this->_EC_size)
		{
			TS_Error("LinkedList<CollType>::operator[]::index out of range");
		}
		Node<CollType>* tmp = this->_LL_Head;
		for (size_t i = 0; i < index; i++)
		{
			tmp = tmp->_N_next;
		}
		return tmp->_N_data;
	}
	template<class CollType>
	const CollType& LinkedList<CollType>::operator[](size_t index) const
	{
		// TODO: insert return statement here
		if (index > this->_EC_size)
		{
			TS_Error("LinkedList<CollType>::operator[]::index out of range");
		}
		Node<CollType>* tmp = this->_LL_Head;
		for (size_t i = 0; i < index; i++)
		{
			tmp = tmp->_N_next;
		}
		return tmp->_N_data;
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
}