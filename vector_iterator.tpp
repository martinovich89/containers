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
//		std::cout << "ptr constructor" << std::endl;
	}

	template <class T>
	vector_iter<T> &vector_iter<T>::operator=(const vector_iter<T> & other)
	{
	//	std::cout << "vector_iter<T> &vector_iter<T>::operator=(const vector_iter<T> & other)" << std::endl;
		vector_const_iter<T>::_ptr = other.vector_const_iter<T>::_ptr;
		return *this;
	}

	template <class T>
	T		&vector_iter<T>::operator*()
	{
		return (*vector_iter<T>::_ptr);
	}

	template <class T>
	T		*vector_iter<T>::operator->()
	{
		return (vector_const_iter<T>::_ptr);
	}

	template <class T>
	T		&vector_iter<T>::operator[](const size_t n)
	{
		return (*(vector_const_iter<T>::_ptr + n));
	}

	template <class T>
	vector_iter<T> &vector_iter<T>::operator++(void)
	{
		vector_iter<T>::_ptr++;
		return *this;
	}

	template <class T>
	vector_iter<T> vector_iter<T>::operator++(int)
	{
		vector_iter<T> tmp(*this);
		operator++();
		return tmp;
	}

	template <class T>
	vector_iter<T> &vector_iter<T>::operator--(void)
	{
		vector_iter<T>::_ptr--;
		return *this;
	}

	template <class T>
	vector_iter<T> vector_iter<T>::operator--(int)
	{
		vector_iter<T> tmp(*this);
		operator--();
		return tmp;
	}

	template <class T>
	vector_iter<T> &vector_iter<T>::operator+=(const int n)
	{
		vector_iter<T>::_ptr += n;
		return *this;
	}

	template <class T>
	vector_iter<T> &vector_iter<T>::operator-=(const int n)
	{
		vector_iter<T>::_ptr -= n;
		return *this;
	}

	template <class T>
	ptrdiff_t	operator-(const vector_iter<T> &lhs, const vector_iter<T> &rhs)
	{
		return (lhs.vector_const_iter<T>::operator->() - rhs.vector_const_iter<T>::operator->());
	}
	
	template <class T>
	vector_iter<T> operator-(const vector_iter<T> &iter, const int n)
	{
		return (vector_iter<T>(const_cast<T*>(iter.vector_const_iter<T>::operator->() - n)));
	}

	template <class T>
	vector_iter<T> operator+(const vector_iter<T> &iter, const int n)
	{
		return (vector_iter<T>(const_cast<T*>(iter.vector_const_iter<T>::operator->() + n)));
	}

	template <class T>
	vector_iter<T> operator+(const int n, const vector_iter<T> &iter)
	{
		return (vector_iter<T>(const_cast<T*>(iter.vector_const_iter<T>::operator->() + n)));
	}
}
