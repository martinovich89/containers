namespace ft
{
    // map_const_iter constructors
    template <class T>
    map_const_iter<T>::map_const_iter()
    {
        _node = NULL;
    }

    template <class T>
    map_const_iter<T>::map_const_iter(const map_const_iter<T> &other)
    {
        *this = other;
    }

    template <class T>
    map_const_iter<T>::map_const_iter(const map_iter<T> &other)
    {
        *this = other;
    }

    template <class T>
    map_const_iter<T>::map_const_iter(const map_const_iter<T>::pointer *ptr)
    {
        // make deep copy of ptr (there is no node function in map_const_iter)
        _ptr = ptr;
    }

    // map_const_iter destructor
    template <class T>
    map_const_iter<T>::~map_const_iter()
    {
    }

    // map_const_iter operator=
    template <class T>
    map_const_iter<T> &map_const_iter<T>::operator=(const map_const_iter<T> &other)
    {
        _node = other._node;
        return (*this);
    }

    // map_const_iter operator==
    template <class T>
    bool map_const_iter<T>::operator==(const map_const_iter<T> &other) const
    {
        if (_node == other._node)
            return (1);
        return (0);
    }

    // map_const_iter operator!=
    template <class T>
    bool map_const_iter<T>::operator!=(const map_const_iter<T> &other) const
    {
        if (_node != other._node)
            return (1);
        return (0);
    }

    // map_const_iter operator<
    template <class T>
    bool map_const_iter<T>::operator<(const map_const_iter<T> &other) const
    {
        if (_node < other._node)
            return (1);
        return (0);
    }


}