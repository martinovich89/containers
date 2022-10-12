#pragma once

namespace ft
{
	template<class T>
	vector_iter<T>::vector_iter()
	: vector_const_iter<T>()
	{

	}

	template<class T>
	vector_iter<T>::~vector_iter()
	{

	}

	template<class T>
	vector_iter<T>::vector_iter(const vector_iter<T> &other)
	: vector_const_iter<T>(other)
	{
		*this = other;
	}

	template<class T>
	vector_iter<T>::vector_iter(T *ptr)
	: vector_const_iter<T>(ptr)
	{
	}

	template <class T>
	vector_iter<T> &vector_iter<T>::operator=(const vector_iter<T> & other)
	{
		vector_const_iter<T>::_ptr = other.vector_const_iter<T>::_ptr;
		return *this;
	}

	template <class T>
	T		&vector_iter<T>::operator*() const
	{
		return (*vector_const_iter<T>::_ptr);
	}

	template <class T>
	T		*vector_iter<T>::operator->()
	{
		return (vector_const_iter<T>::_ptr);
	}

	template <class T>
	T		&vector_iter<T>::operator[](const size_t n)
	{
		return (vector_const_iter<T>::_ptr + n);
	}
}
