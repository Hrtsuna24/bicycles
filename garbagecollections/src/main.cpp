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
		list.AddBack("Node3");
		list.AddBack("Node4");
		list.AddBack("Node5");
		list.AddBack("Node9");
		list.AddBack("Node8");
		list.AddBack("Node7");
		list.AddBack("Node6");
		
		list.RevertAfter(5);
		for (auto& elem : list)
		{
			std::cout << elem._N_data << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}