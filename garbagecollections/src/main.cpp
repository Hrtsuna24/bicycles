#include "Preproc.h"

//#include "Vector.h"
//using HTM::Vector;

#include "LinkedList.h"
#include "LinkedList.cpp"
using HTM::LinkedList;
using std::cout;

int main()
{
	TS_LOG("EntityColl and Iter improvment");
	{
		LinkedList<std::string> list;
		list.AddBack("Node1");
		list.AddBack("Node2");
		list.AddBack("Node4");
		list.InsertAt(2, "Node3");
		list.DeleteAt(2);
		for (size_t i = 0; i < list.Size(); ++i)
		{
			std::string x = list[i];
		}
	}
	return 0;
}