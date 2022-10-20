#pragma once

#include <limits>
#include <cstddef>
#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "iterator_traits.hpp"
#include "vector_iterator.hpp"

namespace ft
{
	template <class iter>
	class reverse_iterator
	{
		public:
			typedef	typename iterator_traits<iter>::iterator_category	iterator_category;
			typedef iter												iterator_type;
			typedef typename iterator_traits<iter>::difference_type		difference_type;
			// typedef iter*												pointer;
			typedef typename std::iterator_traits<iter>::pointer		pointer;
			// typedef iter&												reference;
			typedef typename std::iterator_traits<iter>::reference		reference;
		
		reverse_iterator()
		{

		}

		~reverse_iterator()
		{

		}

		reverse_iterator(const iter &x)
		{
			_iter = x;
		}

		reverse_iterator(const reverse_iterator &other)
		{
			*this = other;
		}

		reverse_iterator &operator++() {
			_iter--;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp;

			tmp = _iter;
			_iter--;
			return (tmp);
		}

		reverse_iterator &operator=(const reverse_iterator &other)
		{
			_iter = &other.operator*();
			return (*this);
		}

		reference operator*() const
		{
			iter tmp = this->_iter;
			return (reference)(*--tmp);
		}

		private:
			iter _iter;
	};
}