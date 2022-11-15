#include <iostream>

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
>
class map
{
	public :
		typedef std::pair<const Key, T> value_type;		
		typedef Key				key_type;
		typedef T				mapped_type;
		typedef Compare			key_compare;
		typedef Allocator		allocator_type;
		typedef T&				reference;
		typedef const T&		const_reference;
		typedef T*				pointer;
		typedef const T*		const_pointer;
		typedef std::ptrdiff_t	difference_type;
		typedef size_t			size_type;
		// typedef iterator		iterator;
		// typedef const_iterator	const_iterator;
		// typedef reverse_iterator	reverse_iterator;
		// typedef const_reverse_iterator	const_reverse_iterator;
		
		map();
		map(const map &other);
		~map();
		map &operator=(const map &other);

		// Iterators
};
