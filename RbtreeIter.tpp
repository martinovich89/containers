namespace ft
{
    // SAME AS RbtreeConstIter but without const
    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc>::RbtreeIter() : _node(NULL), _tree(NULL)
    {

    }

    // constructor that takes a pointer to a node
    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc>::RbtreeIter(TreeNode<T, Vcomp, Alloc> *node, Tree *tree) : _node(node), _tree(tree)
    {

    }

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc>::RbtreeIter(const RbtreeIter<T, Vcomp, Tree, Alloc> &other)
    {
        *this = other;
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc>::RbtreeIter(const RbtreeIter<T, Vcomp, Tree, Alloc>::pointer ptr)
    {
        // make DEEP copy of ptr
        _node = ptr;
    }

    //RbtreeIter destructor
    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc>::~RbtreeIter()
    {
    }

    //RbtreeIter operator=
    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc> &RbtreeIter<T, Vcomp, Tree, Alloc>::operator=(const RbtreeIter<T, Vcomp, Tree, Alloc> &other)
    {
        _node = other._node;
        return (*this);
    }

    //ACCESS OPERATORS
    template <class T, class Vcomp, class Tree, class Alloc>
    typename RbtreeIter<T, Vcomp, Tree, Alloc>::reference RbtreeIter<T, Vcomp, Tree, Alloc>::operator*() const
    {
        return (_node->_data);
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    typename RbtreeIter<T, Vcomp, Tree, Alloc>::pointer RbtreeIter<T, Vcomp, Tree, Alloc>::operator->() const
    {
        return (&(_node->_data));
    }
    
    //ITERATOR OPERATORS
    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc> &RbtreeIter<T, Vcomp, Tree, Alloc>::operator++()
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

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc> RbtreeIter<T, Vcomp, Tree, Alloc>::operator++(int)
    {
        RbtreeIter<T, Vcomp, Tree, Alloc> tmp(*this);
        ++(*this);
        return (tmp);
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc> &RbtreeIter<T, Vcomp, Tree, Alloc>::operator--()
    {
        // check if this is end

        if (*this == _tree->end())
        {
            _node = _tree->root();
            while (_node->_right != NULL)
                _node = _node->_right;
            return (*this);
        }
        if (_node == NULL)
            return (*this);
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

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeIter<T, Vcomp, Tree, Alloc> RbtreeIter<T, Vcomp, Tree, Alloc>::operator--(int)
    {
        std::cout << "operator--" << std::endl;
        RbtreeIter<T, Vcomp, Tree, Alloc> tmp(*this);
        --(*this);
        return (tmp);
    }

    //COMPARISON OPERATORS
    template <class T, class Vcomp, class Tree, class Alloc>
    bool RbtreeIter<T, Vcomp, Tree, Alloc>::operator==(const RbtreeIter<T, Vcomp, Tree, Alloc> &other) const
    {
        return (_node == other._node);
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    bool RbtreeIter<T, Vcomp, Tree, Alloc>::operator!=(const RbtreeIter<T, Vcomp, Tree, Alloc> &other) const
    {
        return (_node != other._node);
    }

    //GETTERS
    template <class T, class Vcomp, class Tree, class Alloc>
    TreeNode<T, Vcomp, Alloc> *RbtreeIter<T, Vcomp, Tree, Alloc>::getNode() const
    {
        return (_node);
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    Tree *RbtreeIter<T, Vcomp, Tree, Alloc>::getTree() const
    {
        return (_tree);
    }

}