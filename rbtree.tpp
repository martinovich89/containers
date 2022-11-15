template <class T, class Compare, class Alloc>
Rbtree<T, Compare, Alloc>::Rbtree() : _root(NULL), _size(0), _comp(), _alloc()
{

}


template <class T, class Compare, class Alloc>
Rbtree<T, Compare, Alloc>::Rbtree(const Rbtree &other)
{
	*this = other;
}

template <class T, class Compare, class Alloc>
Rbtree<T, Compare, Alloc>::~Rbtree()
{
	clear();
}

template <class T, class Compare, class Alloc>
Rbtree<T, Compare, Alloc> &Rbtree<T, Compare, Alloc>::operator=(const Rbtree &other)
{
	if (this != &other)
	{
		clear();
		_root = copy(other._root);
		_size = other._size;
	}
	return *this;
}