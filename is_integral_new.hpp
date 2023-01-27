#pragma once

#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft
{
	struct T
	{
		enum { int_t, float_t } type;
		template< typename Integer, enable_if< is_integral< Integer >::value, bool > = true >
    	T(Integer) : type(int_t)
		{

		}
	};
}