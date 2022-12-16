//public
vector(size_type size, const T &value = T(), const Allocator &alloc = Allocator()) : m_alloc(alloc), m_capacity(size), m_size(size), m_data(m_alloc.allocate(m_capacity))
{
    while (size--)
        m_alloc.construct(m_data + size, value);
}

template <class InputIt>
vector(InputIt a, InputIt b, const Allocator &alloc = Allocator()) : m_alloc(alloc)
{
    typedef typename ft::is_integral< InputIt >::type integral;
    m_init_dispatch(a, b, integral());
}

//private
template <class Integral>
void m_init_dispatch(Integral size, const T &value, ft::true_type)
{
    m_init_size(size, value);
}

template <class InputIt>
void m_init_dispatch(InputIt first, InputIt last, ft::false_type) 
{
    m_init_range(first, last);
}

void m_init_size(size_type size, const T &value)
{
    m_capacity = m_size = size;
    m_data = m_alloc.allocate(m_capacity);
    while (size--)
      m_alloc.construct(m_data + size, value);
}

template <class InputIt>
void m_init_range(InputIt first, InputIt last)
{
    size_type dist = m_capacity = m_size = std::distance(first, last);
    m_data = m_alloc.allocate(m_capacity);
    while (dist)
        m_alloc.construct(m_data + --dist, *--last);
}