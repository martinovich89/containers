namespace ft
{
	// CONSTRUCTORS
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare &comp,
									 const allocator_type &alloc)
		: _root(NULL), _size(0), _comp(comp), _alloc(alloc)
	{
		
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class InputIterator>
	map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last,
									 const key_compare &comp,
									 const allocator_type &alloc)
		: _root(NULL), _size(0), _comp(comp), _alloc(alloc)
	{
		
	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const map &x)
		: _root(NULL), _size(0), _comp(x._comp), _alloc(x._alloc)
	{
		*this = x;
	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map()
	{
		clear();
	}

	// OPERATORS
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc> &map<Key, T, Compare, Alloc>::operator=(const map &x)
	{
		void(x);
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
		return _size == 0;
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::size() const
	{
		return _size;
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::max_size() const
	{
		return std::numeric_limits<size_type>::max() / sizeof(node);
	}

	// ELEMENT ACCESS
	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::mapped_type &map<Key, T, Compare, Alloc>::operator[](const key_type &k)
	{
		// access element
		void(k);
	}

	// MODIFIERS
	template <class Key, class T, class Compare, class Alloc>
	std::pair<typename map<Key, T, Compare, Alloc>::iterator, bool> map<Key, T, Compare, Alloc>::insert(const value_type &val)
	{
		// use the red-black tree insert algorithm
		void(val);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::insert(iterator position, const value_type &val)
	{
		(void)position;
		return insert(val).first;
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
		void(position);
	}

	template <class Key, class T, class Compare, class Alloc>
	size_t map<Key, T, Compare, Alloc>::erase(const key_type &k)
	{
		void(k);
	}

	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
	{
		void(first);
		void(last);
	}

	template <class Key, class T, class Compare, class Alloc>
	void map<Key, T, Compare, Alloc>::swap(map &x)
	{
		void(x);
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
		return value_compare(_comp);
	}

}