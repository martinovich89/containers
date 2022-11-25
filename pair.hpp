#pragma once

#include <limits>
#include <cstddef>
#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "is_integral.hpp"

// make pair class

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(T1()), second(T2()) {}
		pair(const T1 &x, const T2 &y) : first(x), second(y) {}
		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}
		pair &operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return (pair<T1, T2>(t, u));
	}
}