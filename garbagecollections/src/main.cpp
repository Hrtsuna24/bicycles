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
		auto x = list[1];
	}
	return 0;
}