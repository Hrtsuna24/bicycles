#include "Preproc.h"
#include "LLIterator.h"

namespace HTM
{
	template<class LinkedList>
	inline bool LLIterator<LinkedList>::operator==(const LLIterator<LinkedList>& b) const
	{
		return this->_LLI_ptr == b._LLI_ptr;
	}
}