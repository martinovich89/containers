namespace ft
{
    template <class T, class Compare, class Alloc>
    TreeNode<T, Compare, Alloc>::TreeNode() : _left(NULL), _right(NULL), _parent(NULL), _color(false)
    {
    }

    template <class T, class Compare, class Alloc>
    TreeNode<T, Compare, Alloc>::TreeNode(const TreeNode &other) : _left(NULL), _right(NULL), _parent(NULL), _color(false)
    {
        *this = other;
    }

    template <class T, class Compare, class Alloc>
    TreeNode<T, Compare, Alloc>::~TreeNode()
    {
    }

    template <class T, class Compare, class Alloc>
    TreeNode<T, Compare, Alloc> &TreeNode<T, Compare, Alloc>::operator=(const TreeNode &other)
    {
        if (this != &other)
        {
            _data = other._data;
            _left = other._left;
            _right = other._right;
            _parent = other._parent;
            _color = other._color;
        }
        return *this;
    }

}