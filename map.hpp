#pragma once

#include <limits>
#include <cstddef>
#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <functional>
// #include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "is_integral.hpp"
#include "rbtree.hpp"
#include "pair.hpp"


namespace ft
{
	template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> >
	> class map
	{
		public:
			// TYPEDEFS
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef pair<const key_type, mapped_type>							value_type;
			typedef Compare														key_compare;
			class																value_compare;
			typedef Allocator													allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			// iterator typedefs taking rbtree as a base
			typedef ft::RbtreeIter<value_type, value_compare, Rbtree<value_type, value_compare, allocator_type>, allocator_type>			iterator;
			typedef ft::RbtreeConstIter<value_type, value_compare, Rbtree<value_type, value_compare, allocator_type>, allocator_type>		const_iterator;
			// typedef ft::RbtreeIter<const value_type, value_compare, allocator_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef ptrdiff_t													difference_type;
			typedef size_t														size_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
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

		private :
			// ATTRIBUTES
			key_compare _comp;
			value_compare _vcomp;
			Rbtree<value_type, value_compare, allocator_type>	_tree;
	
		public :
			// CONSTRUCTORS
			map();
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
			iterator lower_bound( const Key& key );
			const_iterator lower_bound( const Key& key ) const;
			iterator upper_bound( const Key& key );
			const_iterator upper_bound( const Key& key ) const;
			ft::pair<iterator,iterator> equal_range( const Key& key );
			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

			// CAPACITY
			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			// ELEMENT ACCESS
			iterator find( const Key& key );
			const_iterator find( const Key& key ) const;
			mapped_type &operator[](const key_type &k);
			mapped_type &at(const key_type &k);
			const mapped_type &at(const key_type &k) const;

			// MODIFIERS
			pair<iterator, bool> insert(const value_type &val);
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
			size_type count( const Key& key ) const;
	};
}

#include "map.tpp"