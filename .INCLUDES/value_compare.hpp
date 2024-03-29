#pragma once

#include "map.hpp"

namespace ft
{
	template <class Key, class T, class Compare, class Alloc>
	class typename map<Key, T, Compare, Alloc>::value_compare : public std::binary_function<value_type, value_type, bool>
	{	// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) // constructed with map's comparison object
			{

			}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const first_argument_type& x, const second_argument_type& y) const
			{
				return comp(x.first, y.first);
			}
	};
}