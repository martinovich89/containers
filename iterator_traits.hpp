#pragma once

#include <limits>
#include <cstddef>
#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "vector_iterator.hpp"

namespace ft
{
	template <class iterator>
	struct iterator_traits
	{
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
		typedef typename iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef T*										ptr;
		typedef T&										ref;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	
}