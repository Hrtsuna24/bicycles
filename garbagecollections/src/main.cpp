#include "Preproc.h"

//#include "Vector.h"
//using HTM::Vector;

#include "Array.h"
#include "Array.cpp"
using HTM::Array;


int main()
{
	TS_LOG("EntityColl and Iter improvment");
	{
		Array<float, 5> Arr{ 1, 2, 3, 4, 5 };
		TS_LOG(Arr.Size());
		for (const float& val : Arr)
		{
			std::cout << val << ' ';
		}
		std::cout << '\n';
		Array<float, 5>::Iterator iter = Arr.begin();
		Array<float, 5>::Iterator ArrEnd = Arr.end();
		for (
			;
			iter != ArrEnd;
			++iter
			)
		{
			float x = *iter;
			
		}
	}


	const int& arr = 5;
	int& arr2 = (int&)5;
	return 0;
}