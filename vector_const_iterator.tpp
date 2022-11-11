#pragma once

#include <cstdlib>

namespace ft
{
	template <class T>
	vector_const_iter<T>::vector_const_iter()
	{

	}

	template <class T>
	vector_const_iter<T>::~vector_const_iter()
	{
		
	}

	template <class T>
	vector_const_iter<T>::vector_const_iter(const vector_const_iter<T> &other)
	{
		*this = other;
	}

//	vector_const_iter &operator=(const vector_const_iter &other);

	template <class T>
	vector_const_iter<T>	&vector_const_iter<T>::operator=(const vector_const_iter<T> &other)
	{
		_ptr = other._ptr;
		return (*this);
	}

	template <class T>
	vector_const_iter<T>::vector_const_iter(const T *ptr)
	: _ptr(const_cast<T*>(ptr))
	{
	}

	template <class T>
	bool	vector_const_iter<T>::operator==(const vector_const_iter<T> &other) const
	{
		if (_ptr == other._ptr)
			return (1);
		return (0);
	}

	template <class T>
	bool	vector_const_iter<T>::operator!=(const vector_const_iter<T> &other) const
	{
		if (_ptr != other._ptr)
			return (1);
		return (0);
	}

	

	template <class T>
	bool	vector_const_iter<T>::operator<(const vector_const_iter<T> &other) const
	{
		if (_ptr < other._ptr)
			return (1);
		return (0);
	}

	template <class T>
	bool	vector_const_iter<T>::operator<=(const vector_const_iter<T> &other) const
	{
		if (_ptr <= other._ptr)
			return (1);
		return (0);
	}

	template <class T>
	bool	vector_const_iter<T>::operator>(const vector_const_iter<T> &other) const
	{
		if (_ptr > other._ptr)
			return (1);
		return (0);
	}

	template <class T>
	bool	vector_const_iter<T>::operator>=(const vector_const_iter<T> &other) const
	{
		if (_ptr >= other._ptr)
			return (1);
		return (0);
	}

	template <class T>
	const T		&vector_const_iter<T>::operator*() const
	{
		return (*_ptr);
	}

	template <class T>
	const T		*vector_const_iter<T>::operator->() const
	{
		return (_ptr);
	}

	template <class T>
	vector_const_iter<T> &vector_const_iter<T>::operator++(void)
	{
		_ptr++;
		return (*this);
	}

	template <class T>
	vector_const_iter<T> vector_const_iter<T>::operator++(int)
	{
		vector_const_iter ret(*this);

		_ptr++;
		return (ret);
	}

	template <class T>
	vector_const_iter<T> &vector_const_iter<T>::operator--(void)
	{
		_ptr--;
		return (*this);
	}

	template <class T>
	vector_const_iter<T> vector_const_iter<T>::operator--(int)
	{
		vector_const_iter ret(*this);

		_ptr--;
		return (ret);
	}

	template <class T>
	vector_const_iter<T> &vector_const_iter<T>::operator+=(const int n)
	{
		_ptr += n;
		return (*this);
	}

	template <class T>
	const T		&vector_const_iter<T>::operator[](const size_t n) const
	{
		return (*(_ptr + n));
	}

	template <class T>
	ptrdiff_t	operator-(const vector_const_iter<T> &lhs, const vector_const_iter<T> &rhs)
	{
		return (lhs._ptr - static_cast<ptrdiff_t>(rhs._ptr));
	}

	template <class T>
	vector_const_iter<T> operator-(const vector_const_iter<T> &iter, const int n)
	{
		return (iter._ptr - n);
	}

	template <class T>
	vector_const_iter<T> operator+(const vector_const_iter<T> &iter, const int n)
	{
		return (iter._ptr + n);
	}

	template <class T>
	vector_const_iter<T> operator+(const int n, const vector_const_iter<T> &iter)
	{
		return (iter._ptr + n);
	}
}
