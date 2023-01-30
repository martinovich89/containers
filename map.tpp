namespace ft
{
	// CONSTRUCTORS
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map()
		: _comp(), _vcomp(_comp), _tree(_vcomp)
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
		return(_tree.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::begin() const
	{
		return (_tree.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::end()
	{
		return (_tree.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::end() const
	{
		return (_tree.end());
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
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::find(const Key &k)
	{
		// pair<Key, T> new_pair = make_pair(k, T());
		// return iterator(_tree.find_node(new_pair));
	    pair<const Key, T> new_pair(k, T());
	    typename Rbtree<Key, value_type, value_compare, Alloc>::node *found_node = _tree.find_node(new_pair);
	    return iterator(found_node);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::find(const key_type &k) const
	{
		return _tree.find_node(k);
	}


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
		iterator it(_tree.add_node(val));
		return (ft::pair<iterator, bool> (it, true));
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
		_tree.delete_node(position.getNode());
	}

	template <class Key, class T, class Compare, class Alloc>
	size_t map<Key, T, Compare, Alloc>::erase(const key_type &k)
	{
		// find the node and delete it
		iterator it = find(k);
		if (it != end())
		{
			erase(it);
			return (1);
		}
		return (0);
	}

	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
	{
		// iterate through the list and delete each node
		while (first != last)
			erase(first++);
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