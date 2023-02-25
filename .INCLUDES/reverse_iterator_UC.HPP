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
#include "vector_const_iterator.hpp"

namespace ft
{
	template <class iter>
	class reverse_iterator
	{
		public:
			typedef	typename iterator_traits<iter>::iterator_category	iterator_category;
			typedef iter												iterator_type;
			typedef typename iterator_traits<iter>::difference_type		difference_type;
			typedef typename std::iterator_traits<iter>::pointer		pointer;
			typedef typename std::iterator_traits<iter>::reference		reference;
		
		iterator_type base() const
		{
			return _iter;
		}

		reverse_iterator() : _iter()
		{

		}

		template <class U>
		reverse_iterator(const reverse_iterator< U > &other) : _iter(other.base())
		{
			
		}

		~reverse_iterator()
		{

		}

		reverse_iterator(const iter &other)
		{
			_iter = other;
		}

		// explicit reverse_iterator(iterator_type x) : current(x) { }

		// reverse_iterator(const reverse_iterator &other)
		// {
		// 	*this = other;
		// }

		

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

		reverse_iterator &operator--() {
			_iter++;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp;

			tmp = _iter;
			_iter++;
			return (tmp);
		}

		reverse_iterator &operator=(const reverse_iterator &other)
		{
			_iter = other._iter;
			return *this;
		}

		reference operator*() const
		{
			iterator_type tmp = _iter;
			return const_cast< reference >(*--tmp);
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[]( difference_type n ) const
		{
			return (*(operator->() - n));
		}

		reverse_iterator operator+( difference_type n ) const
		{
			return (reverse_iterator(_iter - n));
		}

		reverse_iterator operator-(const size_t n) const
		{
			return (reverse_iterator(_iter + n));
		}

		reverse_iterator &operator+=(const size_t n)
		{
			_iter -= n;
			return (*this);
		}

		reverse_iterator &operator-=(const size_t n)
		{
			_iter += n;
			return (*this);
		}

		template <typename U>
    	bool operator==(const reverse_iterator<U>& other) const
    	{
    	    return _iter == other.base();
    	}

		// bool operator!=(const reverse_iterator &other) const
		// {
		// 	return (_iter != other._iter);
		// }

		template <typename U>
    	bool operator!=(const reverse_iterator<U>& other) const
    	{
    	    return _iter != other.base();
    	}

		template <typename U>
    	bool operator<(const reverse_iterator<U>& other) const
    	{
    	    return _iter > other.base();
    	}

		template <typename U>
    	bool operator<=(const reverse_iterator<U>& other) const
    	{
    	    return _iter >= other.base();
		}

		template <typename U>
    	bool operator>(const reverse_iterator<U>& other) const
    	{
    	    return _iter < other.base();
    	}

		template <typename U>
    	bool operator>=(const reverse_iterator<U>& other) const
    	{
    	    return _iter <= other.base();
    	}


		private:
			iter _iter;
	};

	template< class Iter >
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
	{
		return (reverse_iterator<Iter>(it.base() - n));
	}

	template< class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type operator-(
			const reverse_iterator<Iterator1>& lhs,
        	const reverse_iterator<Iterator2>& rhs
			)
	{
		// return (distance(const_cast<Iterator1>(rhs.base()), const_cast<Iterator2>(lhs.base())));
		return (rhs.base() - lhs.base());
	}
}