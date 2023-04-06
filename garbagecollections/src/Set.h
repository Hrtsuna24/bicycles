//#pragma once
//#include "EntityCollection.h"
//
//
//namespace HTM
//{
//	template<class CollType>
//	class SetNode
//	{
//		SetNode* _sn_right, * _sn_left;
//		CollType _sn_data;					 //--
//	};										//--
//	//----------------------------------------
//
//
//	template<class CollType>
//	class Set :
//		public EntityCollection<CollType>
//	{
//	public:
//		Set() : EntityCollection(), _s_head(nullptr) {};
//
//
//		void Add(CollType data);
//	private:
//		SetNode<CollType>* _s_head;
//
//		SetNode<CollType>* CreateNode(CollType data, SetNode<CollType>*, SetNode<CollType>*);
//	};
//}
//
