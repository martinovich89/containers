#include <string>
#include <deque>

namespace ft
{
	template< class T, class Container = std::deque<T> >
	class stack
	{
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

		protected:
			container_type c;

		public:
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
			{

			}

			stack& operator=( const stack& other )
			{
				c = other.c;
				return *this;
			}

			bool empty() const
			{
				return c.empty();
			}

			size_type size() const
			{
				return c.size();
			}

			reference top()
			{
				return c.back();
			}

			const_reference top() const
			{
				return c.back();
			}

			void push (const value_type& val)
			{
				c.push_back(val);
			}

			void pop()
			{
				c.pop_back();
			}

			// getters
			container_type getContainer() const
			{
				return c;
			}

	};

	template<class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.getContainer() == rhs.getContainer();
	}

	template<class T, class Container>

	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.getContainer() != rhs.getContainer();
	}

	template<class T, class Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.getContainer() < rhs.getContainer();
	}

	template<class T, class Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.getContainer() <= rhs.getContainer();
	}

	template<class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.getContainer() > rhs.getContainer();
	}

	template<class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.getContainer() >= rhs.getContainer();
	}

}