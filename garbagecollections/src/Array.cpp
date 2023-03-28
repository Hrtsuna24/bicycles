#include "Preproc.h"
#include "Array.h"

namespace HTM
{
	template<typename CollType, size_t S>
	inline constexpr size_t Array<CollType, S>::Size() const
	{
		return size_t(S);
	}
}