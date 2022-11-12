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
			T			&operator*();
			T			*operator->();
			T			&operator[](const size_t n);

			vector_iter &operator++(void);
			vector_iter operator++(int);
			vector_iter &operator--(void);
			vector_iter operator--(int);
			vector_iter &operator+=(const int n);
			vector_iter &operator-=(const int n);
	};
	template <class T>
	ptrdiff_t	operator-(const vector_iter<T> &lhs, const vector_iter<T> &rhs);
	template <class T>
	vector_iter<T> operator-(const vector_iter<T> &iter, const int n);
	template <class T>
	vector_iter<T> operator+(const vector_iter<T> &iter, const int n);
	template <class T>
	vector_iter<T> operator+(const int n, const vector_iter<T> &iter);
}

#include "vector_iterator.tpp"