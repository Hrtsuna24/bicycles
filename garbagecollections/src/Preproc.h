#pragma once
#include <iostream>

#ifdef TS_Debug
#define TS_LOG(x) std::cout << x << '\n' << '\n'
#define TS_WAR(x) std::cerr << x << '\n' << '\n'
#define TS_Error(x) std::cerr << x << '\n' << '\n'
#define CheckIndex(x,y) if(x >= y){__debugbreak();}
#elif TS_Release
#define TS_LOG(x)
#define TS_WAR(x)
#define TS_Error(x)
#define CheckIndex(x,y)
#endif // !TS_Debug