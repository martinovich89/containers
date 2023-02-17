#pragma once

#include <memory>
#include <iostream>
#include <algorithm>
#include <functional>
#include "pair.hpp"
#include "map.hpp"
// #include "iterator_traits.hpp"
// #include "map.hpp"
// #include "pair.hpp"

#define BLACK 0
#define RED 1

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
			// Tree *_tree;
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

	template < class T, class Vcomp, class Tree, class Alloc = std::allocator<T> >
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
			RbtreeIter(TreeNode<T, Vcomp, Alloc> *node, Tree *tree);
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
			Tree *getTree() const;

		private :
			TreeNode<T, Vcomp, Alloc> *_node;
			Tree *_tree;

	};

	template < class T, class Vcomp, class Tree, class Alloc = std::allocator<T> >
	class RbtreeConstIter
	{
		public :
			typedef const T value_type;
			typedef const T& reference;
			typedef const T* pointer;
			typedef std::ptrdiff_t difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;

			RbtreeConstIter();
			RbtreeConstIter(const pointer _data);
			RbtreeConstIter(const TreeNode<T, Vcomp, Alloc> *node, const Tree *tree);
			RbtreeConstIter(const RbtreeIter<T, Vcomp, Tree, Alloc> &other);
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

			const TreeNode<T, Vcomp, Alloc> *getNode() const;
			const Tree *getTree() const;

		private :
			const TreeNode<T, Vcomp, Alloc> *_node;
			const Tree *_tree;
	};

	template < class T, class Vcomp, class Alloc = std::allocator<T> >
	class Rbtree
	{
		public :
			typedef ft::TreeNode<T, Vcomp, Alloc> node;
			typedef ft::RbtreeIter<T, Vcomp, Rbtree, Alloc> iterator;
			typedef ft::RbtreeConstIter<T, Vcomp, Rbtree, Alloc> const_iterator;
			typedef size_t size_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;


			// Rbtree(const Vcomp &comp);
			Rbtree(const Vcomp &comp, const Alloc &alloc = Alloc());
			~Rbtree();
			Rbtree(const Rbtree &other);
			Rbtree &operator=(const Rbtree &other);

			iterator begin();
			iterator end();
			const_iterator begin() const;
			const_iterator end() const;

			node *copy(node *other, node *parent);
			void clear();
			void clear(node *node);

			// ACCESS ELEMENTS
			node *root() const;
			const Vcomp &comp() const;
			size_type	size() const;
			size_type max_size() const;

			node *find_node(const T &value) const;
			// node *find_node(const T &value) const;
			// node *add_node(const T &data);
			// pair<iterator, bool> add_node(const T &data);
			// iterator add_node(const T &data, const void *hint);
			pair<iterator, bool> add_node(const T &data, const void *hint = NULL);
			pair<iterator, bool> add_node(node *new_node);
			// void add_node(node *current, node *other);
			void delete_node(const T &data);
			// void delete_node(iterator it);
			void delete_node(node *current);
			void delete_range(iterator first, iterator last);
			void swap(Rbtree &other);



		private :
			Vcomp		_comp;
			size_type	_size;
			Alloc 		_alloc;
			node		*_root;

			node *minimum(node *current);
			node *maximum(node *current);
			void rebalance_delete(node *current);
			void transplant(node *current, node *child);
			void rotate_left(node *node);
			void rotate_right(node *node);
			void rebalance(node *current);
	};

	// equal
	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	// lexicographical_compare
	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}


	// relational operators
	template <class T, class Vcomp, class Alloc>
	bool	operator ==(const Rbtree<T, Vcomp, Alloc > &lhs, const ft::Rbtree<T, Vcomp, Alloc > &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template <class T, class Vcomp, class Alloc>
	bool	operator <(const Rbtree<T, Vcomp, Alloc > &lhs, const ft::Rbtree<T, Vcomp, Alloc > &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	
	template <class T, class Vcomp, class Alloc>
	bool	operator !=(const Rbtree<T, Vcomp, Alloc > &lhs, const ft::Rbtree<T, Vcomp, Alloc > &rhs)
	{
		return !(lhs == rhs);
	}
	
	template <class T, class Vcomp, class Alloc>
	bool	operator <=(const Rbtree<T, Vcomp, Alloc > &lhs, const ft::Rbtree<T, Vcomp, Alloc > &rhs)
	{
		return lhs < rhs || lhs == rhs;
	}
	
	template <class T, class Vcomp, class Alloc>
	bool	operator >(const Rbtree<T, Vcomp, Alloc > &lhs, const ft::Rbtree<T, Vcomp, Alloc > &rhs)
	{
		return !(lhs <= rhs);
	}
	
	template <class T, class Vcomp, class Alloc>
	bool	operator >=(const Rbtree<T, Vcomp, Alloc > &lhs, const ft::Rbtree<T, Vcomp, Alloc > &rhs)
	{
		return !(lhs < rhs);
	}

}

#include "rbtree.tpp"
#include "tree_node.tpp"
#include "RbtreeIter.tpp"
#include "RbtreeConstIter.tpp"