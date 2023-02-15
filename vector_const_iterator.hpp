#pragma once

#include <limits>
#include <cstddef>
#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "vector.hpp"

namespace ft
{
	template <class T>
	class vector_const_iter : public std::iterator< std::random_access_iterator_tag, T, ptrdiff_t, T*, T& >
	{
		public:
			typedef std::ptrdiff_t							difference_type;
			typedef const T										value_type;
			typedef const T*										pointer;
			typedef const T&										reference;
			typedef std::random_access_iterator_tag			iterator_category;

			vector_const_iter();
			~vector_const_iter();
			vector_const_iter(const vector_const_iter &other);
			vector_const_iter(const T *ptr);
			vector_const_iter &operator=(const vector_const_iter &other);
			bool		operator==(const vector_const_iter &other) const;
			bool		operator!=(const vector_const_iter &other) const;
			bool		operator<(const vector_const_iter &other) const;
			bool		operator<=(const vector_const_iter &other) const;
			bool		operator>(const vector_const_iter &other) const;
			bool		operator>=(const vector_const_iter &other) const;
			const T		&operator*() const;
			const T		*operator->() const;
			vector_const_iter &operator++(void);
			vector_const_iter operator++(int);
			vector_const_iter &operator--(void);
			vector_const_iter operator--(int);
			vector_const_iter &operator+=(const int n);
			vector_const_iter &operator-=(const int n);
			const T		&operator[](const size_t n) const;

		protected:
			T* _ptr;

	};

	template <class T>
	ptrdiff_t	operator-(const vector_const_iter<T> &lhs, const vector_const_iter<T> &rhs);
	template <class T>
	vector_const_iter<T> operator-(const vector_const_iter<T> &iter, const int n);
	template <class T>
	vector_const_iter<T> operator+(const vector_const_iter<T> &iter, const int n);
	template <class T>
	vector_const_iter<T> operator+(const int n, const vector_const_iter<T> &iter);

	template <class T>
	bool operator !=(const vector_const_iter<T> &lhs, const vector_const_iter<T> &rhs)
	{
		std::cout << lhs.operator->() << ' ' << rhs.operator->() << std::endl;
		return lhs.operator->() != rhs.operator->();
	}
}

#include "vector_const_iterator.tpp"