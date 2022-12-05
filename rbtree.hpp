#include <memory>
#include "iterator_traits.hpp"

template < class T, class Vcomp, class Alloc = std::allocator<T> >
class TreeNode
{
	public :
		TreeNode();
		~TreeNode();
		TreeNode(const TreeNode &other);
		TreeNode &operator=(const TreeNode &other);

		get_key();
		get_val();

	private :
		T			_data;
		TreeNode	*_left;
		TreeNode	*_right;
		TreeNode	*_parent;
		bool		_color;
};


template <class T>
class RbtreeIter
{
	public :
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		
		RbtreeIter();
		RbtreeIter(TreeNode *node);
		RbtreeIter(const RbtreeIter &other);
		~RbtreeIter();
		RbtreeIter &operator=(const RbtreeIter &other);
		
		reference operator*() const;
		pointer operator->() const;
		RbtreeIter &operator++();
		RbtreeIter operator++(int);
		RbtreeIter &operator--();
		RbtreeIter operator--(int);
		bool operator==(const RbtreeIter &other) const;
		bool operator!=(const RbtreeIter &other) const;

	private :
		TreeNode *_node;

};

template < class T, class Vcomp = std::less<T>, class Alloc = std::allocator<T> >
class Rbtree
{
	public :
		typedef TreeNode node;
		typedef RbtreeIter<T> iterator;

		Rbtree();
		~Rbtree();
		Rbtree(const Rbtree &other);
		Rbtree &operator=(const Rbtree &other);

		iterator begin();
		iterator end();

		node *copy(node *other);
		void clear();
		void clear(node *node);

		iterator find_node(const T &);
		void add_node(const T &data);
		void delete_node(const T &data);

	private :
		Vcomp	_comp;
		node	*_root;

		void rotation();
};

#include "rbtree.tpp"