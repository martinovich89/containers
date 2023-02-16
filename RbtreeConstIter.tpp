namespace ft
{
    //RbtreeConstIter constructor

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc>::RbtreeConstIter() : _node(NULL), _tree(NULL)
    {

    }

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc>::RbtreeConstIter(const TreeNode<T, Vcomp, Alloc> *node, const Tree *tree) : _node(node), _tree(tree)
    {
        // _node = node;
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc>::RbtreeConstIter(const RbtreeConstIter<T, Vcomp, Tree, Alloc> &other)
    {
        *this = other;
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc>::RbtreeConstIter(const RbtreeIter<T, Vcomp, Tree, Alloc> &other) : _node(other.getNode()), _tree(other.getTree())
    {

    }

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc>::RbtreeConstIter(const RbtreeConstIter<T, Vcomp, Tree, Alloc>::pointer ptr)
    {
        // make DEEP copy of ptr
        _node = ptr;
    }

    //RbtreeConstIter destructor
    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc>::~RbtreeConstIter()
    {
    }

    //RbtreeConstIter operator=
    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc> &RbtreeConstIter<T, Vcomp, Tree, Alloc>::operator=(const RbtreeConstIter<T, Vcomp, Tree, Alloc> &other)
    {
        _node = other._node;
        return (*this);
    }

    //ACCESS OPERATORS
    template <class T, class Vcomp, class Tree, class Alloc>
    typename RbtreeConstIter<T, Vcomp, Tree, Alloc>::reference RbtreeConstIter<T, Vcomp, Tree, Alloc>::operator*() const
    {
        return (_node->_data);
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    typename RbtreeConstIter<T, Vcomp, Tree, Alloc>::pointer RbtreeConstIter<T, Vcomp, Tree, Alloc>::operator->() const
    {
        return (&(_node->_data));
    }

    //INCREMENT/DECREMENT OPERATORS
    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc> &RbtreeConstIter<T, Vcomp, Tree, Alloc>::operator++()
    {
        if (_node->_right)
        {
            _node = _node->_right;
            while (_node->_left)
                _node = _node->_left;
        }
        else
        {
            while (_node->_parent && _node->_parent->_right == _node)
                _node = _node->_parent;
            _node = _node->_parent;
        }
        return (*this);
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc> RbtreeConstIter<T, Vcomp, Tree, Alloc>::operator++(int)
    {
        RbtreeConstIter<T, Vcomp, Tree, Alloc> tmp(*this);
        ++(*this);
        return (tmp);
    }
    
    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc> &RbtreeConstIter<T, Vcomp, Tree, Alloc>::operator--()
    {
        // std::cout << "&operator--" << std::endl;
        if (_node == _tree->begin().getNode())
        {
            _node = NULL;
            return (*this);
        }
        // std::cout << "not begin" << std::endl;
        if (_node->_left)
        {
            _node = _node->_left;
            while (_node->_right)
                _node = _node->_right;
        }
        else
        {
            while (_node->_parent && _node->_parent->_left == _node)
                _node = _node->_parent;
            _node = _node->_parent;
        }
        return (*this);
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    RbtreeConstIter<T, Vcomp, Tree, Alloc> RbtreeConstIter<T, Vcomp, Tree, Alloc>::operator--(int)
    {
        // std::cout << "operator--" << std::endl;
        RbtreeConstIter<T, Vcomp, Tree, Alloc> tmp(*this);
        --(*this);
        return (tmp);
    }

    //COMPARISON OPERATORS
    template <class T, class Vcomp, class Tree, class Alloc>
    bool RbtreeConstIter<T, Vcomp, Tree, Alloc>::operator==(const RbtreeConstIter<T, Vcomp, Tree, Alloc> &other) const
    {
        return (_node == other._node);
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    bool RbtreeConstIter<T, Vcomp, Tree, Alloc>::operator!=(const RbtreeConstIter<T, Vcomp, Tree, Alloc> &other) const
    {
        return (_node != other._node);
    }

    //GETTERS
    template <class T, class Vcomp, class Tree, class Alloc>
    const TreeNode<T, Vcomp, Alloc> *RbtreeConstIter<T, Vcomp, Tree, Alloc>::getNode() const
    {
        return (_node);
    }

    template <class T, class Vcomp, class Tree, class Alloc>
    const Tree *RbtreeConstIter<T, Vcomp, Tree, Alloc>::getTree() const
    {
        return (_tree);
    }

}