#include "Preproc.h"
#include <string>
using std::string;
#include <list>

#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"
using HTM::DoubleLinkedList;

//#include "Set.h"
//#include "Set.cpp"
//using HTM::Set;

int main()
{
	
	DoubleLinkedList<float> list;
	list.InsertBack(4.f);
	list.InsertBack(4.f);
	list.InsertBack(5.f);
	list.InsertBack(4.f);
	;
	list.Delete(list.Find(5.f));
	return 0;
}