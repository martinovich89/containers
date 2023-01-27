namespace ft
{
    // SAME AS RbtreeConstIter but without const
    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc>::RbtreeIter()
    {
        _node = NULL;
    }

    // constructor that takes a pointer to a node
    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc>::RbtreeIter(TreeNode<T, Vcomp, Alloc> *node)
    {
        _node = node;
    }

    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc>::RbtreeIter(const RbtreeIter<T, Vcomp, Alloc> &other)
    {
        *this = other;
    }

    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc>::RbtreeIter(const RbtreeIter<T, Vcomp, Alloc>::pointer ptr)
    {
        // make DEEP copy of ptr
        _node = ptr;
    }

    //RbtreeIter destructor
    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc>::~RbtreeIter()
    {
    }

    //RbtreeIter operator=
    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc> &RbtreeIter<T, Vcomp, Alloc>::operator=(const RbtreeIter<T, Vcomp, Alloc> &other)
    {
        _node = other._node;
        return (*this);
    }

    //ACCESS OPERATORS
    template <class T, class Vcomp, class Alloc>
    typename RbtreeIter<T, Vcomp, Alloc>::reference RbtreeIter<T, Vcomp, Alloc>::operator*() const
    {
        return (_node->_data);
    }

    template <class T, class Vcomp, class Alloc>
    typename RbtreeIter<T, Vcomp, Alloc>::pointer RbtreeIter<T, Vcomp, Alloc>::operator->() const
    {
        return (&(_node->_data));
    }
    
    //ITERATOR OPERATORS
    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc> &RbtreeIter<T, Vcomp, Alloc>::operator++()
    {
        if (_node->_right != NULL)
        {
            _node = _node->_right;
            while (_node->_left != NULL)
                _node = _node->_left;
        }
        else
        {
            while (_node->_parent != NULL && _node->_parent->_right == _node)
                _node = _node->_parent;
            _node = _node->_parent;
        }
        return (*this);
    }

    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc> RbtreeIter<T, Vcomp, Alloc>::operator++(int)
    {
        RbtreeIter<T, Vcomp, Alloc> tmp(*this);
        ++(*this);
        return (tmp);
    }

    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc> &RbtreeIter<T, Vcomp, Alloc>::operator--()
    {
        if (_node->_left != NULL)
        {
            _node = _node->_left;
            while (_node->_right != NULL)
                _node = _node->_right;
        }
        else
        {
            while (_node->_parent != NULL && _node->_parent->_left == _node)
                _node = _node->_parent;
            _node = _node->_parent;
        }
        return (*this);
    }

    template <class T, class Vcomp, class Alloc>
    RbtreeIter<T, Vcomp, Alloc> RbtreeIter<T, Vcomp, Alloc>::operator--(int)
    {
        RbtreeIter<T, Vcomp, Alloc> tmp(*this);
        --(*this);
        return (tmp);
    }

    //COMPARISON OPERATORS
    template <class T, class Vcomp, class Alloc>
    bool RbtreeIter<T, Vcomp, Alloc>::operator==(const RbtreeIter<T, Vcomp, Alloc> &other) const
    {
        return (_node == other._node);
    }

    template <class T, class Vcomp, class Alloc>
    bool RbtreeIter<T, Vcomp, Alloc>::operator!=(const RbtreeIter<T, Vcomp, Alloc> &other) const
    {
        return (_node != other._node);
    }

    //GETTERS
    template <class T, class Vcomp, class Alloc>
    TreeNode<T, Vcomp, Alloc> *RbtreeIter<T, Vcomp, Alloc>::getNode() const
    {
        return (_node);
    }

}