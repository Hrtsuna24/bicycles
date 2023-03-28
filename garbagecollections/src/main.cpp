#include "Preproc.h"

//#include "Vector.h"
//using HTM::Vector;

#include "Vector.h"
#include "Vector.cpp"
using HTM::Vector;


int main()
{
	TS_LOG("EntityColl and Iter improvment");
	{
		Vector<float> Arr{ std::initializer_list<float>{1.f, 2.f, 3.f, 4.f, 5.f } };
		TS_LOG(Arr.Size());
		for (const float& val : Arr)
		{
			std::cout << val << ' ';
		}
		std::cout << '\n';
		Vector<float>::Iterator iter = Arr.begin();
		Vector<float>::Iterator ArrEnd = Arr.end();
		for (
			;
			iter != ArrEnd;
			++iter
			)
		{
			float x = *iter;
			
		}
	}
	return 0;
}