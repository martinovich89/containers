namespace ft
{
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

	// rebalance function
	template <class T, class Compare, class Alloc>
	void Rbtree<T, Compare, Alloc>::rebalance(node *current)
	{
		if (current == _root)
		{
			current->_color = false;
			return ;
		}
		if (current->_parent->_color == false)
			return ;
		node *uncle = current->_parent->_parent->_left;
		if (uncle == current->_parent)
			uncle = current->_parent->_parent->_right;
		if (uncle != NULL && uncle->_color == true)
		{
			current->_parent->_color = false;
			uncle->_color = false;
			current->_parent->_parent->_color = true;
			rebalance(current->_parent->_parent);
			return ;
		}
		if (current->_parent->_parent->_left == current->_parent)
		{			TreeNode	*_root;
			TreeNode	*uncle;
			TreeNode	*grandparent;
			TreeNode	*brother;
			rotate_right(current->_parent->_parent);
			current->_parent->_color = false;
			current->_parent->_right->_color = true;
		}
		else
		{
			if (current->_parent->_left == current)
			{
				rotate_right(current->_parent);
				current = current->_right;
			}
			rotate_left(current->_parent->_parent);
			current->_parent->_color = false;
			current->_parent->_left->_color = true;
		}
	}			TreeNode	*_root;
			TreeNode	*uncle;
			TreeNode	*grandparent;
			TreeNode	*brother;

	// add_node function
	template <class T, class Compare, class Alloc>
	void Rbtree<T, Compare, Alloc>::add_node(const T &data)
	{
		node *new_node = new node(data);
		if (_root == NULL)
		{
			_root = new_node;
			_root->_color = false;
			_size++;
			return ;
		}
		node *current = _root;
		while (current != NULL)
		{
			if (_comp(data, current->_data))
			{
				if (current->_left == NULL)
				{
					current->_left = new_node;
					new_node->_parent = current;
					break ;
				}
				current = current->_left;
			}
			else
			{
				if (current->_right == NULL)
				{
					current->_right = new_node;
					new_node->_parent = current;
					break ;
				}
				current = current->_right;
			}
		}
		_size++;
		rebalance(new_node);
	}
}