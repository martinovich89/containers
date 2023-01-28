#pragma once

#include <memory>
#include <iostream>
#include <algorithm>
#include <functional>
// #include "iterator_traits.hpp"
// #include "map.hpp"
// #include "pair.hpp"

namespace ft
{
	template < class T, class Vcomp, class Alloc = std::allocator<T> >
	class TreeNode
	{
		public :
			TreeNode();
			TreeNode(const T &data);
			~TreeNode();
			TreeNode(const TreeNode &other);
			TreeNode &operator=(const TreeNode &other);

			T &getData();

			T			_data;
			TreeNode	*_left;
			TreeNode	*_right;
			TreeNode	*_parent;
			bool		_color;
	};

	// template < class T, class Vcomp, class Alloc = std::allocator<T> >
	// struct TreeNode
	// {
	// 	TreeNode();
	// 	TreeNode(const T &data);
	// 	~TreeNode();
	// 	TreeNode(const TreeNode &other);
	// 	TreeNode &operator=(const TreeNode &other);

	// 	T &getData();

	// 	T			_data;
	// 	TreeNode	*_left;
	// 	TreeNode	*_right;
	// 	TreeNode	*_parent;
	// 	bool		_color;
	// };

	/*
	q: what template parameters should be here?
	*/
	
	/*
	a: T, Vcomp, Alloc
	*/

	template < class T, class Vcomp, class Alloc = std::allocator<T> >
	class RbtreeIter
	{
		public :
			typedef T								value_type;
			typedef T&								reference;
			typedef T*								pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;

			RbtreeIter();
			RbtreeIter(const pointer ptr);
			RbtreeIter(TreeNode<T, Vcomp, Alloc> *node);
			RbtreeIter(const RbtreeIter &other);
			~RbtreeIter();
			RbtreeIter &operator=(const RbtreeIter &other);

			reference operator*() const;
			pointer operator->() const;
			RbtreeIter &operator++();
			RbtreeIter operator++(int);
			RbtreeIter &operator--();
			RbtreeIter operator--(int);
			bool operator==(const RbtreeIter &other) const;
			bool operator!=(const RbtreeIter &other) const;

			TreeNode<T, Vcomp, Alloc> *getNode() const;

		private :
			TreeNode<T, Vcomp, Alloc> *_node;

	};

	template < class T, class Vcomp, class Alloc = std::allocator<T> >
	class RbtreeConstIter
	{
		public :
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef std::ptrdiff_t difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;

			RbtreeConstIter();
			RbtreeConstIter(const pointer node);
			RbtreeConstIter(const TreeNode<T, Vcomp, Alloc> *node);
			RbtreeConstIter(const RbtreeIter<T, Vcomp, Alloc> &other);
			RbtreeConstIter(const RbtreeConstIter &other);
			~RbtreeConstIter();
			RbtreeConstIter &operator=(const RbtreeConstIter &other);

			reference operator*() const;
			pointer operator->() const;
			RbtreeConstIter &operator++();
			RbtreeConstIter operator++(int);
			RbtreeConstIter &operator--();
			RbtreeConstIter operator--(int);
			bool operator==(const RbtreeConstIter &other) const;
			bool operator!=(const RbtreeConstIter &other) const;

		private :
			TreeNode<T, Vcomp, Alloc> *_node;
	};

	template < class Key, class T = int, class Vcomp = std::less<T>, class Alloc = std::allocator<T> >
	class Rbtree
	{
		public :
			typedef ft::TreeNode<T, Vcomp, Alloc> node;
			typedef ft::RbtreeIter<T, Vcomp, Alloc> iterator;
			typedef ft::RbtreeConstIter<T, Vcomp, Alloc> const_iterator;
			typedef size_t size_type;
			typedef Key key_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;


			Rbtree(const Vcomp &comp);
			// Rbtree(const Vcomp &comp, const Alloc &alloc = Alloc());
			~Rbtree();
			Rbtree(const Rbtree &other);
			Rbtree &operator=(const Rbtree &other);

			iterator begin();
			iterator end();

			node *copy(node *other);
			void clear();
			void clear(node *node);

			// ACCESS ELEMENTS
			node &root() const;
			Vcomp &comp() const;
			size_type	size() const;

			iterator find_node(const T &);
			node *add_node(const T &data);
			iterator add_node(const T &data, const void *hint);
			node *add_node(node *new_node);
			// void add_node(node *current, node *other);
			void delete_node(const T &data);
			void delete_node(iterator it);
			void delete_range(iterator first, iterator last);

		private :
			Vcomp		_comp;
			node		*_root;
			size_type	_size;
			Alloc 		_alloc;

			node *minimum(node *current);
			node *maximum(node *current);
			void rebalance_delete(node *current);
			void transplant(node *current, node *child);
			void rotate_left(node *node);
			void rotate_right(node *node);
			void rebalance(node *current);
	};
}

#include "rbtree.tpp"
#include "tree_node.tpp"
#include "RbtreeIter.tpp"
#include "RbtreeConstIter.tpp"