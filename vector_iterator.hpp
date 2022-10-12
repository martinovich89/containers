#pragma once

#include <limits>
#include <cstddef>
#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "vector.hpp"
#include "vector_const_iterator.hpp"

namespace ft
{
	template <class T>
	class vector_iter : public vector_const_iter<T>
	{
		public:
			vector_iter();
			~vector_iter();
			vector_iter(const vector_iter &other);
			vector_iter(T *ptr);

			vector_iter & operator=(const vector_iter & other);
			T			&operator*() const;
			T			*operator->();
			T			&operator[](const size_t n);
	};
}

#include "vector_iterator.tpp"