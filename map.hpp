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

namespace ft
{
	template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
	> class map
	{
	public:
		// TYPEDEFS
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef std::pair<const key_type, mapped_type>		value_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef map_iter<value_type>						iterator;
		typedef map_const_iter<value_type>					const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		// CONSTRUCTORS
//		map();
		explicit map(const key_compare &comp,
					 const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());
		map(const map &x);
		~map();

		// OPERATORS
		map &operator=(const map &x);

		// ITERATORS
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		// CAPACITY
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		// ELEMENT ACCESS
		mapped_type &operator[](const key_type &k);
		mapped_type &at(const key_type &k);
		const mapped_type &at(const key_type &k) const;

		// MODIFIERS
		std::pair<iterator, bool> insert(const value_type &val);
		iterator insert(iterator position, const value_type &val);
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);
		void erase(iterator position);
		size_type erase(const key_type &k);
		void erase(iterator first, iterator last);
		void swap(map &x);
		void clear();

		// OBSERVERS
		key_compare key_comp() const;
		value_compare value_comp() const;

	};
}

#include "map.tpp"