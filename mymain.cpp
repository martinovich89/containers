#include "vector.hpp"
#include <cstdlib>

#ifdef __STL__
# define ft std
#endif

typedef struct s_max_size_test
{
	size_t a;
	size_t b;
	int		c[42];
}	t_max_size_test;

int main(void)
{

	ft::vector<short> my_vector0;
	ft::vector<int> my_vector1;
	ft::vector<t_max_size_test> my_vector3;

	my_vector0.push_back(42);
	my_vector0.push_back(21);
	const ft::vector<short> my_vector2(my_vector0);

	std::cout << my_vector0.max_size() << " | " << (size_t)~0 / (sizeof(short) * 2) << std::endl;
	std::cout << my_vector1.max_size() << " | " << (size_t)~0 / (sizeof(int) * 2) << std::endl;
	std::cout << my_vector2.max_size() << " | " << (size_t)~0 / (sizeof(size_t) * 2) << std::endl;
	std::cout << my_vector3.max_size() << " | " << (size_t)~0 / (sizeof(t_max_size_test) * 2) << std::endl;

	ft::vector<short>::iterator iter;
	iter = my_vector0.begin();
	std::cout << *iter << std::endl;


	my_vector1.push_back(42);
	ft::vector<int>::reverse_iterator riter;
	riter = my_vector1.rbegin();
	std::cout << *riter << std::endl;

	ft::vector<short>::const_iterator citer;
	citer = my_vector2.begin();
	std::cout << *citer << std::endl;

	
	return (0);
}