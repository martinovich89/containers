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
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		// TYPEDEFS
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef vector_iter<T>									iterator;
		typedef vector_const_iter<T>							const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef	ptrdiff_t										difference_type;
		typedef size_t											size_type;

		// CONSTRUCTORS	
		explicit vector(const allocator_type &alloc = allocator_type());
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type());
		vector(const vector &x);
		~vector();

		// CAPACITY
		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);

		// ELEMENT ACCESS
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference front();
		const_reference front() const;
    	reference back();
		const_reference back() const;
		
		// MODIFIERS
		template <class InputIterator>
			void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
		iterator insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
			iterator insert (iterator position, InputIterator first, InputIterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (vector& x);
		void clear();

		// ITERATORS
		iterator begin(void);
		const_iterator begin(void) const;
		iterator end(void);
		const_iterator end(void) const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

	private:
		Alloc		_alloc;
		size_type	_capacity;
		size_type	_size;
		value_type *_data;

		template <class InputIterator>
			iterator _insert_dispatch(iterator position, InputIterator first, InputIterator last, ft::false_type);
		iterator _insert_dispatch(iterator position, size_type n, const value_type& val, ft::true_type);
		template <class InputIterator>
			iterator _insert_range(iterator position, InputIterator first, InputIterator last);
		template <class InputIterator>
			void _constructor_dispatch(InputIterator first, InputIterator last, ft::false_type);
		template <class InputIterator>
			void _constructor_dispatch(size_type n, const value_type& val, ft::true_type);
		// UTILITY
		void	_check_range(size_type n) const;
	};
}

#include "vector.tpp"