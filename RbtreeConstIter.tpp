namespace ft
{
    //RbtreeConstIter constructors
    template <class T, class Vcomp, class Alloc>
    RbtreeConstIter<T, Vcomp, Alloc>::RbtreeConstIter()
    {
        _node = NULL;
    }

    template <class T, class Vcomp, class Alloc>
    RbtreeConstIter<T, Vcomp, Alloc>::RbtreeConstIter(const RbtreeConstIter<T, Vcomp, Alloc> &other)
    {
        *this = other;
    }

    template <class T, class Vcomp, class Alloc>
    RbtreeConstIter<T, Vcomp, Alloc>::RbtreeConstIter(const RbtreeIter<T, Vcomp, Alloc> &other)
    {
        *this = other;
    }

    template <class T, class Vcomp, class Alloc>
    RbtreeConstIter<T, Vcomp, Alloc>::RbtreeConstIter(const RbtreeConstIter<T, Vcomp, Alloc>::pointer ptr)
    {
        // make DEEP copy of ptr
        _node = ptr;
    }

    //RbtreeConstIter destructor
    template <class T, class Vcomp, class Alloc>
    RbtreeConstIter<T, Vcomp, Alloc>::~RbtreeConstIter()
    {
    }

    //RbtreeConstIter operator=
    template <class T, class Vcomp, class Alloc>
    RbtreeConstIter<T, Vcomp, Alloc> &RbtreeConstIter<T, Vcomp, Alloc>::operator=(const RbtreeConstIter<T, Vcomp, Alloc> &other)
    {
        _node = other._node;
        return (*this);
    }

    //ACCESS OPERATORS
    template <class T, class Vcomp, class Alloc>
    typename RbtreeConstIter<T, Vcomp, Alloc>::reference RbtreeConstIter<T, Vcomp, Alloc>::operator*() const
    {
        return (_node->_data);
    }

    template <class T, class Vcomp, class Alloc>
    typename RbtreeConstIter<T, Vcomp, Alloc>::pointer RbtreeConstIter<T, Vcomp, Alloc>::operator->() const
    {
        return (&(_node->_data));
    }

}