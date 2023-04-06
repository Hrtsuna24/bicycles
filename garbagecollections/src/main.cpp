#include "Preproc.h"
#include <string>
using std::string;
//#include "Vector.h"
//using HTM::Vector;

#include "vEctOr.h"
#include "vEctOr.cpp"
using HTM::vEctOr;


vEctOr<double> rVec()
{
	vEctOr<double> list{ 1, 2, 3, 4, 5, -8 };
	return list;
}


int main()
{
	vEctOr<double> list{1, 2, 3, 4, 5, -8};
	vEctOr<double> list2(list);
	vEctOr<double> list3;
	list3 = list;
	vEctOr<double> list4 = rVec();
	return 0;
}