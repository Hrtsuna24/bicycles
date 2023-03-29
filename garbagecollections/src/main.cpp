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
		list.AddBack("Danylo");
		list.AddBack("Anya");
		list.AddBack("Oleh");
		list.AddFront("Oleh");
		list.AddBack("Max");
		list.SubBack();
		list.SubFront();

		std::string str = list.Back();
		str = list.Front();
		auto x = list[2];
		LinkedList<std::string> listcopy(list);
	}
	return 0;
}