namespace ft
{
	// CONSTRUCTORS
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map()
		: _tree()
	{
		
	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare &comp,
									 const allocator_type &alloc)
		: _tree(comp, alloc)
	{
		
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class InputIterator>
	map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last,
									 const key_compare &comp,
									 const allocator_type &alloc)
		: _tree(first, last, comp, alloc)
	{
		
	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const map &x)
		: _tree(x._tree)
	{

	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map()
	{
		// clear();
	}

	// OPERATORS
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc> &map<Key, T, Compare, Alloc>::operator=(const map &x)
	{
		_tree.copy(x._tree);
	}

	// ITERATORS
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::begin()
	{
		
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::begin() const
	{
		
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::end()
	{
		return iterator(NULL);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::end() const
	{
		return const_iterator(NULL);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rbegin()
	{

	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rbegin() const
	{

	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rend()
	{
		return reverse_iterator(NULL);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rend() const
	{
		return const_reverse_iterator(NULL);
	}

	// CAPACITY
	template <class Key, class T, class Compare, class Alloc>
	bool map<Key, T, Compare, Alloc>::empty() const
	{
		return _tree.size() == 0;
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::size() const
	{
		return _tree.size();
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::max_size() const
	{
		return std::numeric_limits<size_type>::max() / sizeof(_tree.find_node(0));
	}

	// ELEMENT ACCESS
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::mapped_type &map<Key, T, Compare, Alloc>::operator[](const key_type &k)
	{
		// access element
		(void)k;
	}

	// MODIFIERS
	template <class Key, class T, class Compare, class Alloc>
	typename ft::pair< typename map<Key, T, Compare, Alloc>::iterator, bool> map<Key, T, Compare, Alloc>::insert(const typename map<Key, T, Compare, Alloc>::value_type &val)
	{
		// use the Rbtree add_node function
		return (_tree.add_node(val));
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::insert(iterator position, const value_type &val)
	{
		//Inserts value in the position as close as possible to the position just prior to pos
		return (_tree.add_node(val, position.getNode()));		
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class InputIterator>
	void map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
	{
		for (; first != last; ++first)
			insert(*first);
	}

	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::erase(iterator position)
	{
		// use the redblack tree delete function
		(void)(position);
	}

	template <class Key, class T, class Compare, class Alloc>
	size_t map<Key, T, Compare, Alloc>::erase(const key_type &k)
	{
		(void)k;
	}

	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
	{
		(void)(first);
		(void)(last);
	}

	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::swap(map &x)
	{
		(void)x;
	}

	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::clear()
	{
		erase(begin(), end());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::key_compare map<Key, T, Compare, Alloc>::key_comp() const
	{
		return _tree.comp();
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::value_compare map<Key, T, Compare, Alloc>::value_comp() const
	{
		return value_compare(_tree.comp());
	}

}