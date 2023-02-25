#pragma once

#include <limits>
#include <cstddef>
#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
// #include "iterator_traits.hpp"
#include "map.hpp"

namespace ft
{
    // bidirectional iterator inheritance
    template <class T>
    class map_const_iter : public std::iterator< std::bidirectional_iterator_tag, T, ptrdiff_t, T*, T& >
    {
        public:
            typedef T                               value_type;
            typedef T                               *pointer;
            typedef T                               &reference;
            typedef std::ptrdiff_t                  difference_type;
            typedef std::bidirectional_iterator_tag iterator_category;

            map_const_iter() : _ptr(NULL);
            map_const_iter(const map_const_iter &other);
            map_const_iter &operator=(const map_const_iter &other);
            ~map_const_iter();
            // map_const_iter(pointer ptr) : _ptr(ptr);

            // map_const_iter &operator++();
            // map_const_iter operator++(int);
            // map_const_iter &operator--();
            // map_const_iter operator--(int);

            // reference operator*() const;
            // pointer operator->() const;

            bool operator==(const map_const_iter &other) const;
            bool operator!=(const map_const_iter &other) const;

        private:
            pointer _ptr;
    };
}

#include "map_const_iter.tpp"