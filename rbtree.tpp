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

template <class T, class Compare, class Alloc>
typename Rbtree<T, Compare, Alloc>::node *Rbtree<T, Compare, Alloc>::copy(node *other)
{
	if (other == NULL)
		return NULL;
	node *new_node = new node(*other);
	new_node->_left = copy(other->_left);
	new_node->_right = copy(other->_right);
	return new_node;
}

template <class T, class Compare, class Alloc>
void Rbtree<T, Compare, Alloc>::clear()
{
	clear(_root);
	_root = NULL;
	_size = 0;
}

template <class T, class Compare, class Alloc>
void Rbtree<T, Compare, Alloc>::clear(node *node)
{
	if (node == NULL)
		return ;
	clear(node->_left);
	clear(node->_right);
	delete node;
}