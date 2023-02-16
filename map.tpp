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
		: _comp(comp), _vcomp(_comp), _tree(_vcomp, alloc)
	{
		
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class InputIterator>
	map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last,
									 const key_compare &comp,
									 const allocator_type &alloc)
		: _comp(comp), _vcomp(_comp), _tree(_vcomp, alloc)
	{
		insert(first, last);
	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const map &x)
		: _comp(), _vcomp(_comp), _tree(x._tree)
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
		_tree.operator=(x._tree);
		return (*this);
	}

	// Relational operators
	template <class Key, class T, class Compare, class Alloc>
	bool map<Key, T, Compare, Alloc>::operator==(const map &x) const
	{
		return (_tree == x._tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool map<Key, T, Compare, Alloc>::operator!=(const map &x) const
	{
		return (_tree != x._tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool map<Key, T, Compare, Alloc>::operator<(const map &x) const
	{
		return (_tree < x._tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool map<Key, T, Compare, Alloc>::operator<=(const map &x) const
	{
		return (_tree <= x._tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool map<Key, T, Compare, Alloc>::operator>(const map &x) const
	{
		return (_tree > x._tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool map<Key, T, Compare, Alloc>::operator>=(const map &x) const
	{
		return (_tree >= x._tree);
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
		return reverse_iterator(_tree.end());
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

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::lower_bound(const key_type &k)
	{
		for (iterator it = begin(); it != end(); it++)
		{
			if (!_comp(it->first, k))
				return it;
		}
		return end();
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::lower_bound(const key_type &k) const
	{
		for (const_iterator it = begin(); it != end(); it++)
		{
			if (!_comp(it->first, k))
				return it;
		}
		return end();
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type &k)
	{
		for (iterator it = begin(); it != end(); it++)
		{
			if (_comp(k, it->first))
				return it;
		}
		return end();
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type &k) const
	{
		for (const_iterator it = begin(); it != end(); it++)
		{
			if (_comp(k, it->first))
				return it;
		}
		return end();
	}

	template <class Key, class T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator> map<Key, T, Compare, Alloc>::equal_range(const key_type &k)
	{
		return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
	}

	template <class Key, class T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator> map<Key, T, Compare, Alloc>::equal_range(const key_type &k) const
	{
		return pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
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
		// use rebind to get the allocator type of the node
		typedef typename Alloc::template rebind<TreeNode<value_type, value_compare, Alloc> >::other node_allocator;
		return (node_allocator().max_size());
		// return (std::numeric_limits<size_type>::max() / (sizeof(TreeNode<value_type, value_compare, Alloc>) * 2));
		// return _tree.max_size();
	}

	// ELEMENT ACCESS
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::find(const Key &k)
	{
		// pair<Key, T> new_pair = make_pair(k, T());
		// return iterator(_tree.find_node(new_pair));
	    pair<const Key, T> new_pair(k, T());
	    typename Rbtree<value_type, value_compare, Alloc>::node *found_node = _tree.find_node(new_pair);
	    return iterator(found_node, &_tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::find(const key_type &k) const
	{
		pair<const Key, T> new_pair(k, T());
		return const_iterator(_tree.find_node(new_pair), &_tree);
	}


	// template <class Key, class T, class Compare, class Alloc>
	// typename map<Key, T, Compare, Alloc>::mapped_type &map<Key, T, Compare, Alloc>::operator[](const key_type &k)
	// {
	// 	// access element
	// 	mapped_type &val = find(k)->second;
	// 	if (val == end())
	// 	{
	// 		// insert element
	// 		insert(ft::pair<key_type, mapped_type>(k, mapped_type()));
	// 	}
	// 	return val;
	// }

	template <class Key, class T, class Compare, class Allocator>
	T& map<Key, T, Compare, Allocator>::operator[](const Key& key)
	{

		if (find(key) != end())
			return find(key)->second;

		pair<const key_type, mapped_type> value(key, T());
		pair<iterator, bool> result = insert(value);
		if (result.second == false)
			result.first->second = T();
			
		return result.first->second;
	}

	// MODIFIERS
	template <class Key, class T, class Compare, class Alloc>
	typename ft::pair< typename map<Key, T, Compare, Alloc>::iterator, bool> map<Key, T, Compare, Alloc>::insert(const typename map<Key, T, Compare, Alloc>::value_type &val)
	{
		// std::cout << "KEK" << std::endl;
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
	void map<Key, T, Compare, Alloc>::(InputIterator first, InputIterator last)
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
		return _comp;
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::value_compare map<Key, T, Compare, Alloc>::value_comp() const
	{
		return value_compare(_tree.comp());
	}

	// count
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::count(const key_type &k) const
	{
		// find the node and delete it
		const_iterator it = find(k);
		if (it != end())
			return (1);
		return (0);
	}

}