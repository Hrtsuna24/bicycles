#include "Preproc.h"
#include "LinkedList.h"

namespace HTM
{
	template<class CollType>
	void LinkedList<CollType>::TailCheck()
	{
		while (this->_LL_Tail->_N_next)
		{
			this->_LL_Tail = this->_LL_Tail->_N_next;
		}
	}


	template<class CollType>
	LinkedList<CollType>::~LinkedList()
	{
		Node<CollType>* tmpnode = this->_LL_Head;
		while (tmpnode)
		{
			Node<CollType>* tmpnode = this->_LL_Head->_N_next;
			delete[]this->_LL_Head;
		}
	}
	template<class CollType>
	Node<CollType>* LinkedList<CollType>::CreateNode(const CollType& data)
	{
		Node<CollType>* tmpnode = new Node<CollType>;
		tmpnode->_N_data = data;
		return tmpnode;
	}


	template<class CollType>
	void LinkedList<CollType>::AddBack(const CollType& data)
	{
		Node<CollType>* tmp = CreateNode(data);
		if (!this->_EC_size)
		{
			this->_LL_Head = tmp;
			this->_LL_Tail = tmp;
		}
		else
		{
			this->_LL_Tail->_N_next = tmp;
		}
		TailCheck();
		this->_EC_size++;
	}
	template<class CollType>
	CollType& LinkedList<CollType>::operator[](size_t index)
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
	void LinkedList<CollType>::Clear()
	{
		Node<CollType>
			*tmp = this->_LL_Head,
			*tmpNext = this->_LL_Head->_N_next
			;
		while (tmpNext)
		{
			delete[]tmp;
			tmp = tmpNext;
			tmpNext = this->_LL_Head->_N_next;
		}
	}
}