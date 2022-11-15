#include <memory>

template < class T, class Vcomp, class Alloc = std::allocator<T> >
class TreeNode
{
	public :
		TreeNode();
		~TreeNode();
		TreeNode(const TreeNode &other);
		Treenode &operator=(const TreeNode &other);



		get_key();
		get_val();

	private :
		T _data;
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
			TreeNode *node;
};

template < class T, class Vcomp, class Alloc = std::allocator<T> >
class Rbtree
{
	public :
		typedef TreeNode node;
		Rbtree();

		add_node(const T &data);
	private :
		Vcomp _comp;
};

#include "red-black_tree.tpp"