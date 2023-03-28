#include "Preproc.h"

//#include "Vector.h"
//using HTM::Vector;

#include "Vector.h"
#include "Vector.cpp"
using HTM::Vector;
using std::cout;

int main()
{
	TS_LOG("EntityColl and Iter improvment");
	{
		Vector<int> Arr;
		Arr.PushBack(5);
		Arr.PushBack(5);
		Arr.Insert(6, 1);
		Arr.Empty();
		Arr.Top();

	}
	return 0;
}