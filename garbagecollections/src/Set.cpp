#include "Preproc.h"
#include "Set.h"


namespace HTM
{
	template<class CollType>
	void Set<CollType>::Add(CollType data)
	{
		if (!this->_s_head)
		{

		}
	}

	template<class CollType>
	SetNode<CollType>* Set<CollType>::CreateNode(CollType data, SetNode<CollType>* right = nullptr, SetNode<CollType>* left = nullptr)
	{
		SetNode<CollType>* NewNode = new SetNode<CollType>(data);
		NewNode->_sn_right = right;
		NewNode->_sn_left = left;
		return NewNode;
	}
}