namespace ft
{
	template < class Key, class T, class Vcomp, class Alloc>
	Rbtree<Key, T, Vcomp, Alloc>::Rbtree(const Vcomp &comp) : _comp(comp), _root(NULL), _size(0), _alloc()
	{
		
	}

	// template < class Key, class T, class Vcomp, class Alloc >
	// Rbtree<Key, T, Vcomp, Alloc>::Rbtree(const Vcomp &comp, const Alloc &alloc)
	// 	: _comp(comp), _root(NULL), _size(0), _alloc(alloc)
	// {
		
	// }

	template < class Key, class T, class Vcomp, class Alloc >
	Rbtree<Key, T, Vcomp, Alloc>::Rbtree(const Rbtree &other)
	{
		*this = other;
	}

	template < class Key, class T, class Vcomp, class Alloc >
	Rbtree<Key, T, Vcomp, Alloc>::~Rbtree()
	{
		clear();
	}

	template < class Key, class T, class Vcomp, class Alloc >
	Rbtree<Key, T, Vcomp, Alloc> &Rbtree<Key, T, Vcomp, Alloc>::operator=(const Rbtree &other)
	{
		if (this != &other)
		{
			clear();
			_root = copy(other._root);
			_size = other._size;
		}
		return *this;
	}

	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::node *Rbtree<Key, T, Vcomp, Alloc>::copy(node *other)
	{
		if (other == NULL)
			return NULL;
		typename Alloc::template rebind<node>::other allocator;
		node *new_node =  allocator.allocate(1);
		allocator.construct(new_node, *other);
		new_node->_left = copy(other->_left);
		new_node->_right = copy(other->_right);
		return new_node;
	}

	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::clear()
	{
		clear(_root);
		_root = NULL;
		_size = 0;
	}

	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::clear(node *node)
	{
		if (node == NULL)
			return ;
		clear(node->_left);
		clear(node->_right);
		delete node;
	}

	// ACCESS FUNCTIONS
		// get root
	template < class Key, class T, class Vcomp, class Alloc >
	TreeNode<T, Vcomp, Alloc> &Rbtree<Key, T, Vcomp, Alloc>::root() const
	{
		return _root;
	}

		// get comp
	template < class Key, class T, class Vcomp, class Alloc >
	Vcomp &Rbtree<Key, T, Vcomp, Alloc>::comp() const
	{
		return _comp;
	}

		// get size
	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::size_type Rbtree<Key, T, Vcomp, Alloc>::size() const
	{
		return _size;
	}

	// rotate_left function

	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::rotate_left(node *current)
	{
		node *right = current->_right;
		current->_right = right->_left;
		if (right->_left != NULL)
			right->_left->_parent = current;
		right->_parent = current->_parent;
		if (current->_parent == NULL)
			_root = right;
		else if (current == current->_parent->_left)
			current->_parent->_left = right;
		else
			current->_parent->_right = right;
		right->_left = current;
		current->_parent = right;
	}

	// rotate_right function
	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::rotate_right(node *current)
	{
		node *left = current->_left;
		current->_left = left->_right;
		if (left->_right != NULL)
			left->_right->_parent = current;
		left->_parent = current->_parent;
		if (current->_parent == NULL)
			_root = left;
		else if (current == current->_parent->_right)
			current->_parent->_right = left;
		else
			current->_parent->_left = left;
		left->_right = current;
		current->_parent = left;
	}

	// rebalance function
	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::rebalance(node *current)
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
		{
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
	}

	// add_node function
	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::node *Rbtree<Key, T, Vcomp, Alloc>::add_node(node *new_node)
	{
		if (_root == NULL)
		{
			_root = new_node;
			_root->_color = false;
			_size++;
			return  NULL;
		}
		node *current = _root;
		while (current != NULL)
		{
			if (_comp(new_node->_data, current->_data))
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
		return (new_node);
	}

	// // add_node function using T data
	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::node *Rbtree<Key, T, Vcomp, Alloc>::add_node(const T &data)
	{
		typename Alloc::template rebind<node>::other allocator;
		node *new_node = allocator.allocate(1);
		allocator.construct(new_node, data);
		add_node(new_node);
		return new_node;
	}

	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::iterator Rbtree<Key, T, Vcomp, Alloc>::add_node(const T &data, const void *hint)
	{
		typename Alloc::template rebind<node>::other allocator;
		node *new_node = allocator.allocate(1, hint);
		allocator.construct(new_node, data);
		add_node(new_node);
		return iterator(new_node);
	}

	// begin and end
	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::iterator Rbtree<Key, T, Vcomp, Alloc>::begin()
	{
		node *current = _root;
		while (current->_left != NULL)
			current = current->_left;
		return iterator(current);
	}

	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::iterator Rbtree<Key, T, Vcomp, Alloc>::end()
	{
		node *current = NULL;
		return iterator(current);
	}

	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::const_iterator Rbtree<Key, T, Vcomp, Alloc>::begin() const
	{
		node *current = _root;
		while (current->_left != NULL)
			current = current->_left;
		return const_iterator(current);
	}

	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::const_iterator Rbtree<Key, T, Vcomp, Alloc>::end() const
	{
		node *current = NULL;
		return const_iterator(current);
	}

	// find_node function
	// template < class Key, class T, class Vcomp, class Alloc >
	// typename Rbtree<Key, T, Vcomp, Alloc>::node *Rbtree<Key, T, Vcomp, Alloc>::find_node(const T &value) const
	// {
	// 	node *current = _root;
	// 	while (current != NULL)
	// 	{
	// 		if (_comp(value, current->_data))
	// 			current = current->_left;
	// 		else if (_comp(current->_data, value))
	// 			current = current->_right;
	// 		else
	// 			break ;
	// 	}
	// 	return current;
	// }

	// find_node function with const
	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::node *Rbtree<Key, T, Vcomp, Alloc>::find_node(const T &value) const
	{
		node *current = _root;
		while (current != NULL)
		{
			if (_comp(value, current->_data))
				current = current->_left;
			else if (_comp(current->_data, value))
				current = current->_right;
			else
				break ;
		}
		return current;
	}

	// delete_node function using value
	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::delete_node(const T &value)
	{
		node *current = _root;
		while (current != NULL)
		{
			if (_comp(value, current->_data))
				current = current->_left;
			else if (_comp(current->_data, value))
				current = current->_right;
			else
				break ;
		}
		if (current == NULL)
			return ;
		delete_node(current);
	}

	//	transplant function
	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::transplant(node *current, node *child)
	{
		if (current->_parent == NULL)
			_root = child;
		else if (current == current->_parent->_left)
			current->_parent->_left = child;
		else
			current->_parent->_right = child;
		if (child != NULL)
			child->_parent = current->_parent;
	}

	// minimum function
	template < class Key, class T, class Vcomp, class Alloc >
	typename Rbtree<Key, T, Vcomp, Alloc>::node *Rbtree<Key, T, Vcomp, Alloc>::minimum(node *current)
	{
		while (current->_left != NULL)
			current = current->_left;
		return current;
	}

	// rebalance_delete function
	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::rebalance_delete(node *current)
	{
	    while (current != _root && current->_color == false)
	    {
	        if (current->_parent == NULL)
	            return;
	        if (current == current->_parent->_left)
	        {
	            node *brother = current->_parent->_right;
	            if (brother == NULL)
	                return;
	            if (brother->_color == true)
	            {
	                brother->_color = false;
	                current->_parent->_color = true;
	                rotate_left(current->_parent);
	                brother = current->_parent->_right;
	            }
	            if (brother->_left == NULL || brother->_right == NULL)
	                return;
	            if (brother->_left->_color == false && brother->_right->_color == false)
	            {
	                brother->_color = true;
	                current = current->_parent;
	            }
	            else
	            {
	                if (brother->_right->_color == false)
	                {
	                    brother->_left->_color = false;
	                    brother->_color = true;
	                    rotate_right(brother);
	                    brother = current->_parent->_right;
	                }
	                brother->_color = current->_parent->_color;
	                current->_parent->_color = false;
	                brother->_right->_color = false;
	                rotate_left(current->_parent);
	                current = _root;
	            }
	        }
	        else
	        {
	            node *brother = current->_parent->_left;
	            if (brother == NULL)
	                return;
	            if (brother->_color == true)
	            {
	                brother->_color = false;
	                current->_parent->_color = true;
	                rotate_right(current->_parent);
	                brother = current->_parent->_left;
	            }
	            if (brother->_right == NULL || brother->_left == NULL)
	                return;
	            if (brother->_right->_color == false && brother->_left->_color == false)
	            {
	                brother->_color = true;
	                current = current->_parent;
	            }
	            else
	            {
	                if (brother->_left->_color == false)
	                {
	                    brother->_right->_color = false;
	                    brother->_color = true;
	                    rotate_left(brother);
	                    brother = current->_parent->_left;
	                }
	                brother->_color = current->_parent->_color;
	                current->_parent->_color = false;
	                brother->_left->_color = false;
	                rotate_right(current->_parent);
	                current = _root;
	            }
	        }
	    }
		current->_color = false;
	}

	// delete_node function using iterator, using rebalance function
	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::delete_node(iterator it)
	{
		node *current = it.getNode();
		node *tmp = current;
		node *child = NULL;
		bool color = current->_color;

		if (current->_left == NULL)
		{
			child = current->_right;
			transplant(current, current->_right);
		}
		else if (current->_right == NULL)
		{
			child = current->_left;
			transplant(current, current->_left);
		}
		else
		{
			tmp = minimum(current->_right);
			color = tmp->_color;
			child = tmp->_right;
			if (tmp->_parent == current)
				child->_parent = tmp;
			else
			{
				transplant(tmp, tmp->_right);
				tmp->_right = current->_right;
				tmp->_right->_parent = tmp;
			}
			transplant(current, tmp);
			tmp->_left = current->_left;
			tmp->_left->_parent = tmp;
			tmp->_color = current->_color;
		}
		if (color == false && child != NULL)
			rebalance_delete(child);
		delete current;
		_size--;
	}

	// delete node using iterator range
	template < class Key, class T, class Vcomp, class Alloc >
	void Rbtree<Key, T, Vcomp, Alloc>::delete_range(iterator first, iterator last)
	{
		while (first != last)
		{
			iterator tmp = first;
			first++;
			delete_node(tmp);
		}
	}

}