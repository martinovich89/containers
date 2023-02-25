#ifdef __STL__
#include <vector>
#include <map>
namespace ft = std;
// # define VECTOR_NAME "stlvector"
#else
#include "vector.hpp"
#include "map.hpp"
// # define VECTOR_NAME "ftvector"
#endif
#include <iostream>
#include <string>
#include <numeric>

#define VECTOR_NAME "vector"

// define colors
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

// define uncolor
#define RESET "\033[0m"

void print_vector_data(ft::vector<int> &v)
{
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

void print_vector(ft::vector<int> &v)
{
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "empty: " << v.empty() << std::endl;
	std::cout << "max_size: " << v.max_size() << std::endl;
	std::cout << "print_data: " << std::endl;
	print_vector_data(v);
}

void vector_constructors()
{
	// std::cout << "default constructor" << std::endl;
	// same blue color

	std::cout << BLUE << "default constructor" << RESET << std::endl;
	ft::vector<int> v1;
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "fill constructor" << RESET << std::endl;
	ft::vector<int> v2(5, 42);
	print_vector(v2);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "range constructor" << RESET << std::endl;
	ft::vector<int> v3(v2.begin(), v2.begin() + 3);
	print_vector(v3);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "copy constructor" << RESET << std::endl;
	ft::vector<int> v4(v3);
	print_vector(v4);
	std::cout << "-------------------------------" << std::endl;
}

void assign_operator()
{
	ft::vector<int> v1(5, 42);
	ft::vector<int> v2;
	v2 = v1;
	print_vector(v2);
	std::cout << "-------------------------------" << std::endl;
}

void assign()
{
	ft::vector<int> v1(5, 42);
	ft::vector<int> v2;
	v2.assign(v1.begin(), v1.begin() + 3);
	print_vector(v2);
	std::cout << "-------------------------------" << std::endl;
}

void capacity()
{
	std::cout << BLUE << "filled vector" << RESET << std::endl;
	ft::vector<int> v1(5, 42);
	print_vector(v1);
	// modify vector multiple times
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "add 6 elements" << RESET << std::endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "remove 3 elements" << RESET << std::endl;
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "resize 10" << RESET << std::endl;
	v1.resize(10);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "resize 3" << RESET << std::endl;
	v1.resize(3);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "reserve 100" << RESET << std::endl;
	v1.reserve(100);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "reserve 1" << RESET << std::endl;
	v1.reserve(1);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << std::endl;
}

void relational()
{
	ft::vector<int> v1(5, 42);
	ft::vector<int> v2(5, 42);
	ft::vector<int> v3(5, 43);
	ft::vector<int> v4(6, 42);

	std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
	std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
	std::cout << "v1 == v4: " << (v1 == v4) << std::endl;
	std::cout << "v1 != v2: " << (v1 != v2) << std::endl;
	std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
	std::cout << "v1 != v4: " << (v1 != v4) << std::endl;
	std::cout << "v1 < v2: " << (v1 < v2) << std::endl;
	std::cout << "v1 < v3: " << (v1 < v3) << std::endl;
	std::cout << "v1 < v4: " << (v1 < v4) << std::endl;
	std::cout << "v1 <= v2: " << (v1 <= v2) << std::endl;
	std::cout << "v1 <= v3: " << (v1 <= v3) << std::endl;
	std::cout << "v1 <= v4: " << (v1 <= v4) << std::endl;
	std::cout << "v1 > v2: " << (v1 > v2) << std::endl;
	std::cout << "v1 > v3: " << (v1 > v3) << std::endl;
	std::cout << "v1 > v4: " << (v1 > v4) << std::endl;

	std::cout << "-------------------------------" << std::endl;
}

void element_access()
{
	ft::vector<int> v1(5, 42);
	std::cout << "v1[0]: " << v1[0] << std::endl;
	std::cout << "v1[4]: " << v1[4] << std::endl;
	std::cout << "v1.at(0): " << v1.at(0) << std::endl;
	std::cout << "v1.front(): " << v1.front() << std::endl;
	std::cout << "v1.back(): " << v1.back() << std::endl;

	// modify vector
	v1.push_back(1);
	v1.push_back(2);

	std::cout << "v1[0]: " << v1[0] << std::endl;
	std::cout << "v1[5]: " << v1[5] << std::endl;
	std::cout << "v1.back(): " << v1.back() << std::endl;

	std::cout << "-------------------------------" << std::endl;
}

void modifiers()
{
	std::cout << BLUE << "filled vector" << RESET << std::endl;
	ft::vector<int> v1(5, 42);
	print_vector(v1);
	// modify vector multiple times
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "insert 1 element" << RESET << std::endl;
	v1.insert(v1.begin(), 1);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "insert 3 elements" << RESET << std::endl;
	v1.insert(v1.begin() + 2, 3, 1);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "insert 3 elements from another vector" << RESET << std::endl;
	ft::vector<int> v2(3, 1);
	v1.insert(v1.begin() + 2, v2.begin(), v2.end());
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "erase 1 element" << RESET << std::endl;
	v1.erase(v1.begin() + 2);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "erase 3 elements" << RESET << std::endl;
	v1.erase(v1.begin() + 2, v1.begin() + 5);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "swap with another vector" << RESET << std::endl;
	ft::vector<int> v3(3, 1);
	v1.swap(v3);
	print_vector(v1);
	print_vector(v3);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "clear" << RESET << std::endl;
	v1.clear();
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "push_back 1 element" << RESET << std::endl;
	v1.push_back(1);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "push_back 3 elements" << RESET << std::endl;
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "pop_back" << RESET << std::endl;
	v1.pop_back();
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "assign 1 element" << RESET << std::endl;
	v1.assign(1, 42);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << BLUE << "assign 3 elements" << RESET << std::endl;
	v1.assign(3, 42);
	print_vector(v1);
	std::cout << "-------------------------------" << std::endl;

	std::cout << std::endl;
}

void iterators()
{
	ft::vector<int> v1;
	for (int i = 0; i < 5; i++)
		v1.push_back(i);
	ft::vector<int>::iterator it = v1.begin();
	ft::vector<int>::iterator ite = v1.end();

	std::cout << BLUE << "v1: " << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	// const iterators
	ft::vector<int> v2;
	for (int i = 0; i < 5; i++)
		v2.push_back(i);
	ft::vector<int>::const_iterator cit = v2.begin();
	ft::vector<int>::const_iterator cite = v2.end();

	std::cout << BLUE << "v2: " << RESET << std::endl;
	while (cit != cite)
	{
		std::cout << *cit << " ";
		cit++;
	}
	std::cout << std::endl;

	// now reverse iterators
	ft::vector<int> v3;
	for (int i = 0; i < 5; i++)
		v3.push_back(i);
	ft::vector<int>::reverse_iterator rit = v3.rbegin();
	ft::vector<int>::reverse_iterator rite = v3.rend();

	std::cout << BLUE << "v3: " << RESET << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << " ";
		rit++;
	}
	std::cout << std::endl;

	// const reverse iterators
	ft::vector<int> v4;
	for (int i = 0; i < 5; i++)
		v4.push_back(i);
	ft::vector<int>::const_reverse_iterator crit = v4.rbegin();
	ft::vector<int>::const_reverse_iterator crite = v4.rend();

	std::cout << BLUE << "v4: " << RESET << std::endl;
	while (crit != crite)
	{
		std::cout << *crit << " ";
		crit++;
	}
	std::cout << std::endl;

	// opposite behavior
	ft::vector<int> v5;
	for (int i = 0; i < 5; i++)
		v5.push_back(i);
	ft::vector<int>::iterator it5 = v5.end();
	ft::vector<int>::iterator ite5 = v5.begin();

	std::cout << BLUE << "v5: " << RESET << std::endl;
	while (it5-- != ite5)
	{
		std::cout << *it5 << " ";
	}
	std::cout << std::endl;

	// with const iterators
	ft::vector<int> v6;
	for (int i = 0; i < 5; i++)
		v6.push_back(i);
	ft::vector<int>::const_iterator cit6 = v6.end();
	ft::vector<int>::const_iterator cite6 = v6.begin();

	std::cout << BLUE << "v6: " << RESET << std::endl;
	while (cit6-- != cite6)
	{
		std::cout << *cit6 << " ";
	}
	std::cout << std::endl;

	// now reverse iterators
	ft::vector<int> v7;
	for (int i = 0; i < 5; i++)
		v7.push_back(i);
	ft::vector<int>::reverse_iterator rit7 = v7.rend();
	ft::vector<int>::reverse_iterator rite7 = v7.rbegin();

	std::cout << BLUE << "v7: " << RESET << std::endl;
	while (rit7-- != rite7)
	{
		std::cout << *rit7 << " ";
		// rit7--;
	}
	std::cout << std::endl;

	// and const reverse iterators
	ft::vector<int> v8;
	for (int i = 0; i < 5; i++)
		v8.push_back(i);
	ft::vector<int>::const_reverse_iterator crit8 = v8.rend();
	ft::vector<int>::const_reverse_iterator crite8 = v8.rbegin();

	std::cout << BLUE << "v8: " << RESET << std::endl;
	while (crit8-- != crite8)
	{
		std::cout << *crit8 << " ";
		// crit8--;
	}
	std::cout << std::endl;

	std::cout << "-------------------------------" << std::endl;
}

void lexicographical_compare()
{
	ft::vector<int> v1;
	for (int i = 0; i < 5; i++)
		v1.push_back(i);
	ft::vector<int> v2;
	for (int i = 0; i < 5; i++)
		v2.push_back(i);

	std::cout << BLUE << "v1: " << RESET << std::endl;
	print_vector(v1);
	std::cout << BLUE << "v2: " << RESET << std::endl;
	print_vector(v2);

	std::cout << BLUE << "v1 vs v2" << RESET << std::endl;
	std::cout << "v1 == v2: " << (v1 == v2) << std::endl;
	std::cout << "v1 != v2: " << (v1 != v2) << std::endl;
	std::cout << "v1 < v2: " << (v1 < v2) << std::endl;
	std::cout << "v1 <= v2: " << (v1 <= v2) << std::endl;
	std::cout << "v1 > v2: " << (v1 > v2) << std::endl;
	std::cout << "v1 >= v2: " << (v1 >= v2) << std::endl;

	std::cout << "-------------------------------" << std::endl;

	ft::vector<int> v3;
	for (int i = 1; i < 6; i++)
		v3.push_back(i);
	ft::vector<int> v4;
	for (int i = -1; i < 4; i++)
		v4.push_back(i);

	std::cout << BLUE << "v3: " << RESET << std::endl;
	print_vector(v3);
	std::cout << BLUE << "v4: " << RESET << std::endl;
	print_vector(v4);

	std::cout << BLUE << "v1 vs v3" << RESET << std::endl;
	std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
	std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
	std::cout << "v1 < v3: " << (v1 < v3) << std::endl;
	std::cout << "v1 <= v3: " << (v1 <= v3) << std::endl;
	std::cout << "v1 > v3: " << (v1 > v3) << std::endl;
	std::cout << "v1 >= v3: " << (v1 >= v3) << std::endl;

	std::cout << BLUE << "v1 vs v4" << RESET << std::endl;
	std::cout << "v1 == v4: " << (v1 == v4) << std::endl;
	std::cout << "v1 != v4: " << (v1 != v4) << std::endl;
	std::cout << "v1 < v4: " << (v1 < v4) << std::endl;
	std::cout << "v1 <= v4: " << (v1 <= v4) << std::endl;
	std::cout << "v1 > v4: " << (v1 > v4) << std::endl;
	std::cout << "v1 >= v4: " << (v1 >= v4) << std::endl;

	std::cout << "-------------------------------" << std::endl;
}

int main()
{
	// test vector constructors
	try
	{
		std::cout << YELLOW << "=====> VECTOR CONSTRUCTORS <=====" << RESET << std::endl;
		vector_constructors();
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test operator=
	try
	{
		std::cout << YELLOW << "=====> VECTOR OPERATOR= <=====" << RESET << std::endl;
		assign_operator();
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test assign
	try
	{
		std::cout << YELLOW << "=====> VECTOR ASSIGN <=====" << RESET << std::endl;
		assign();
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test capacity functions
	try
	{
		std::cout << YELLOW << "=====> VECTOR CAPACITY <=====" << RESET << std::endl;
		capacity();
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test relational operators
	try
	{
		std::cout << YELLOW << "=====> VECTOR RELATIONAL OPERATORS <=====" << RESET << std::endl;
		relational();
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test element access
	try
	{
		std::cout << YELLOW << "=====> VECTOR ELEMENT ACCESS <=====" << RESET << std::endl;
		element_access();
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test modifiers
	try
	{
		std::cout << YELLOW << "=====> VECTOR MODIFIERS <=====" << RESET << std::endl;
		modifiers();
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test iterators
	try
	{
		std::cout << YELLOW << "=====> VECTOR ITERATORS <=====" << RESET << std::endl;
		iterators();
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// test non-member functions
	try
	{
		std::cout << YELLOW << "=====> LEXICOGRAPHICAL COMPARISON <=====" << RESET << std::endl;
		lexicographical_compare();
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}