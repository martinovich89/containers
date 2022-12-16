
namespace ft
{
	//CONSTRUCTORS

	template < class T, class Alloc >
	vector<T, Alloc>::~vector()
	{
		clear();
		_alloc.deallocate(_data, _capacity);
	}

	template < class T, class Alloc >
	vector<T, Alloc>::vector(const typename vector<T, Alloc>::allocator_type &alloc)
	:	_alloc(alloc),
		_capacity(0),
		_size(0),
		_data(_alloc.allocate(0))
	{

	}

	template < class T, class Alloc >
	vector<T, Alloc>::vector(typename vector<T, Alloc>::size_type n, const typename vector<T, Alloc>::value_type &val, const typename vector<T, Alloc>::allocator_type &alloc)
	:	_alloc(alloc),
		_capacity(0),
		_size(0),
		_data(_alloc.allocate(0))
	{
		for (size_t i = 0; i < n; i++)
			_alloc.construct(_data + i, val);
	}

	template < class T, class Alloc >
	void vector<T, Alloc>::_constructor_size(typename vector<T, Alloc>::size_type n, const typename vector<T, Alloc>::value_type &val)
	{
		_capacity = size;
		_size = size;
	    _data = _alloc.allocate(_capacity);
		size_t	i = 0;
		while (i < n)
		{
			_alloc.construct(_data + i, val);
			i++;
		}
	}

	template < class T, class Alloc >
	template <class InputIterator>
	void vector<T, Alloc>::_constructor_range(InputIterator first, InputIterator last)
	{
		_capacity = std::distance(first, last);
		_size = _capacity;
		_data = _alloc.allocate(_capacity);
		iterator it = first;
		while (it != last)
		{
			push_back(*it);
			it++;
		}
	}


	template < class T, class Alloc >
	template <class InputIterator>
	void vector<T, Alloc>::_constructor_dispatch(InputIterator first, InputIterator last, const Alloc& alloc, const false_type&)
	{
		_constructor_range(first, last);
	}
	
	template < class T, class Alloc >
	template <class Integral>
	void vector<T, Alloc>::_constructor_dispatch(Integral n, const value_type& val, const Alloc& alloc, const true_type&)
	{
		_constructor_size(size, val);
	}

	template <class T, class Alloc>
	template< class InputIterator >
	vector<T, Alloc>::vector(InputIterator first, InputIterator last, const Alloc& alloc) : _alloc(alloc)
	{
		typedef is_integral<InputIterator> is_int;
		_constructor_dispatch(first, last, is_int());
	}


	template < class T, class Alloc >
	vector<T, Alloc>::vector(const vector &x)
	:	_alloc(x._alloc),
		_capacity(x._size),
		_size(_capacity),
		_data(_alloc.allocate(_capacity))
	{
		typename vector<T, Alloc>::const_iterator it = x.begin();
		while (it != x.end())
			_alloc.construct(_data++, *it++);
		_data -= _size;
	}

	// CAPACITY

	template < class T, class Alloc >
	typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
	{
		return (_size);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
	{
		return (~0UL / (sizeof(T) * 2));
	}

	template < class T, class Alloc >
	void vector<T, Alloc>::resize(typename vector<T, Alloc>::size_type n, typename vector<T, Alloc>::value_type val)
	{
		if (n > _capacity)
			reserve(n);
		while (_size-- > n)
			_alloc.destroy(_data + _size);
		while (_size++ < n)
			_alloc.construct(_data + _size, val);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
	{
		return (_capacity);
	}

	template < class T, class Alloc >
	bool vector<T, Alloc>::empty() const
	{
		return ((!_size));
	}

	template < class T, class Alloc >
	void vector<T, Alloc>::reserve(typename vector<T, Alloc>::size_type n)
	{
		if (n > max_size())
			throw std::length_error(std::string("vector::") + "reserve");
		if (n > _capacity)
		{
			T *new_vector = _alloc.allocate(n);
			typename vector<T, Alloc>::iterator it = begin();
			size_t	i = 0;
			for (; it != end(); it++)
			{
				_alloc.construct(new_vector + i, *it);
				_alloc.destroy(it.operator->());
				i++;
			}
			_alloc.deallocate(_data, _capacity);
			_capacity = n;
			_data = new_vector;
		}
	}

	// ELEMENT ACCESS
	template < class T, class Alloc >
	typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](typename vector<T, Alloc>::size_type n)
	{
		return _data[n];
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](typename vector<T, Alloc>::size_type n) const
	{
		return _data[n];
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::reference vector<T, Alloc>::at(typename vector<T, Alloc>::size_type n)
	{
		_check_range(n);
		return (_data[n]);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(typename vector<T, Alloc>::size_type n) const
	{
		_check_range(n);
		return (_data[n]);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::reference vector<T, Alloc>::front()
	{
		return (_data[0]);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
	{
		return (_data[0]);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::reference vector<T, Alloc>::back()
	{
		return  (_data[_size - 1]);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
	{
		return  (_data[_size - 1]);
	}

	// MODIFIERS
	template < class T, class Alloc >
	template < class InputIterator >
	void vector<T, Alloc>::assign(InputIterator first, InputIterator last)
	{
		typename vector<T, Alloc>::size_type size(first - last);

		if (size > _capacity)
			reserve(size);
		while (_size-- > size)
			_alloc.destroy(_data + size);
		while (_size < size)
			_alloc.construct(_data + _size++, T());
		std::copy(first, last, _data);

	}

	template < class T, class Alloc >
	void vector<T, Alloc>::assign (typename vector<T, Alloc>::size_type n, const typename vector<T, Alloc>::value_type& val)
	{
		typename vector<T, Alloc>::size_type begin = _data;
		typename vector<T, Alloc>::size_type end = _data + _size;

		if (n > _capacity)
			reserve(n);
		while (_size-- > n)
			_alloc.destroy(_data + n);
		while (_size < n)
			_alloc.construct(_data + _size++, val);
		std::fill(begin, end, val);
	}

	template < class T, class Alloc >
	void vector<T, Alloc>::push_back(const typename vector<T, Alloc>::value_type& val)
	{
		if (_capacity == 0)
			this->reserve(1);
		else if (_size == _capacity)
			this->reserve(_size * 2);
		_alloc.construct(this->end().operator->(), val);
		_size++;
	}

	template < class T, class Alloc >
	void vector<T, Alloc>::pop_back()
	{
		_alloc.destroy(this->end());
		_size--;
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(
		typename vector<T, Alloc>::iterator position, const vector<T, Alloc>::value_type& val)
	{
		// insert before position
		size_type		size = _size + 1;
		iterator		new_pos;

		if (_capacity < size)
		{
			if (size > 2 * _size)
				reserve(size);
			else
				reserve(2 * _size);
		}

		while (size > _size)
			_alloc.construct(_data + --size, T());

		new_pos = begin() + (position - begin());
		std::copy_backward(new_pos, end(), end() + 1);
		_alloc.construct(new_pos.operator->(), val);
		_size++;

		return (new_pos);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(typename vector<T, Alloc>::iterator position, typename vector<T, Alloc>::size_type n, const typename vector<T, Alloc>::value_type& val)
	{
		size_type		size = _size + n;
		const size_type	new_size = size;
		const size_type	offset = position - begin();
		iterator		new_pos;

		if (_capacity < size)
		{
			if (size > 2 * _size)
				reserve(size);
			else
				reserve(2 * _size);
		}

		while (size > _size)
			_alloc.construct(_data + --size, T());
		new_pos = begin() + offset;

		std::copy_backward(new_pos, end(), end() + n);
		std::fill(new_pos, new_pos + n, val);

		_size = new_size;
		return new_pos;
	}

	template < class T, class Alloc >
	template < class InputIterator >
		typename vector<T, Alloc>::iterator vector<T, Alloc>::_insert_range(typename vector<T, Alloc>::iterator position, InputIterator first, InputIterator last)
	{
		const difference_type	count = last - first;
		size_type				size = _size + count;
		const size_type			new_size = size;
		const difference_type	offset = position - begin();
		iterator				new_pos, it;

		if (_capacity < size)
		{
			if (size > 2 * _size)
				reserve(size);
			else
				reserve(2 * _size);
		}
		it = end();
		new_pos = _data + offset;
		while (size > _size && it > new_pos)
			_alloc.construct(_data + --size, *--it);
		while (size > _size)
			_alloc.construct(_data + --size, *--last);
		while (it > new_pos)
			_data[--size] = *--it;
		std::copy(first, last, new_pos);
		_size = new_size;
		return new_pos;
	}

	// these 2 functions are used to choose the correct insert function
	// 2 different prototypes were needed to avoid ambiguity
	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::_insert_dispatch(typename vector<T, Alloc>::iterator position, typename vector<T, Alloc>::size_type n, const typename vector<T, Alloc>::value_type& val, true_type)
	{
		return insert(position, n, val);
	}

	template < class T, class Alloc >
	template < class InputIterator >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::_insert_dispatch(typename vector<T, Alloc>::iterator position, InputIterator first, InputIterator last, false_type)
	{
		return _insert_range(position, first, last);
	}

	template < class T, class Alloc >
	template < class InputIterator >
		typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(typename vector<T, Alloc>::iterator position, InputIterator first, InputIterator last)
	{
		typedef is_integral<InputIterator> is_int;
		return _insert_dispatch(position, first, last, is_int());
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(typename vector<T, Alloc>::iterator position)
	{
		//erase element at position

		_alloc.destroy(position.operator->());
		std::copy(position + 1, end(), position);
		_size--;
		return position;
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(typename vector<T, Alloc>::iterator first, typename vector<T, Alloc>::iterator last)
	{
		// erase elements in range [first, last)

		iterator	it = first;
		
		while (it != last)
			_alloc.destroy(it++.operator->());
		std::copy(last, end(), first);
		_size -= last - first;
		return first;
	}

	template < class T, class Alloc >
	void vector<T, Alloc>::swap(vector &x)
	{
		(void)x;
	}

	template < class T, class Alloc >
	void	vector<T, Alloc>::_check_range(typename vector<T, Alloc>::size_type n) const
	{
		if (n > _size - 1)
		{
			std::ostringstream error("vector::");
			error << "_check_range" << ": element " << n << "out of range (max " << _size << ")";
			throw std::out_of_range(error.str());
		}
	}

	// ITERATORS

	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::begin(void)
	{
		// std::cout << "begin" << std::endl;
		return iterator(_data);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin(void) const
	{
		return const_iterator(_data);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::end(void)
	{
		return iterator(_data + _size);
	}

	template < class T, class Alloc >
	typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end(void) const
	{
		return const_iterator(_data + _size);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin(void)
	{
		return (reverse_iterator(end()));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin(void) const
	{
		return (reverse_iterator(end()));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend(void)
	{
		return (reverse_iterator(begin()));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend(void) const
	{
		return (reverse_iterator(begin()));
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::clear()
	{
		while (_size)
			_alloc.destroy(_data + --_size);
	}
}
