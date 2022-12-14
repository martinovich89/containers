#ifdef __STL__
# include <vector>
# include <map>
namespace ft = std;
# define VECTOR_NAME "stlvector"
#else
# include "vector.hpp"
# define VECTOR_NAME "ftvector"
#endif
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

//#include "vector.hpp"
//#include "map.hpp"
//#include "pair.hpp"

// test vector and iterator classes
int main()
{
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;

	// set some values:
	for (int i=1; i<=5; i++) myvector.push_back(i); // myvector: 1 2 3 4 5

	it = myvector.begin();
	++it;       // "it" points now to number 2           ^

	// std::cout << "myvector contains:";
	// for (it=myvector.begin(); it<myvector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << std::endl;

	myvector.insert (it,10);                        // myvector: 1 10 2 3 4 5

	std::cout << VECTOR_NAME << " contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	// "it" still points to number 2                      ^
	myvector.insert (it,2,20);                      // myvector: 1 10 20 20 2 3 4 5

	std::cout << VECTOR_NAME << " contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	--it;       // "it" points now to the second 20            ^

	std::cout << VECTOR_NAME << " contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::vector<int> myvector2 (2,30);
	myvector.insert (it,myvector2.begin(),myvector2.end());
	// myvector: 1 10 20 30 30 20 2 3 4 5
	// "it" no longer valid, get a new one:
	it = myvector.begin();

	it += 3;    // "it" points now to number 30                ^

	std::cout << VECTOR_NAME << " contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	myvector.insert (it, myvector.begin(),myvector.begin()+5);
	// myvector: 1 10 20 1 10 20 30 30 20 2 3 4 5
	// "it" no longer valid, get a new one:
	it = myvector.begin();

	it += 5;    // "it" points now to number 20                ^

	myvector.erase (it);
	// myvector: 1 10 20 1 10 30 30 20 2 3 4 5
	// "it" no longer valid, get a new one:
	it = myvector.begin();

	it += 6;    // "it" points now to number 30                ^

	myvector.erase (it,it+3);
	// myvector: 1 10 20 1 10 30 2 3 4 5
	// "it" no longer valid, get a new one:
	it = myvector.begin();

	it += 5;    // "it" points now to number

	std::cout << VECTOR_NAME << " contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;	

	// test reverse iterator
	it = myvector.begin();
	ft::vector<int>::reverse_iterator rit(it);

	std::cout << VECTOR_NAME << " contains:";
//	for (rit=myvector.rbegin(); rit < myvector.rend(); rit++)
		std::cout << ' ' << *rit;
	std::cout << std::endl;

	int arr[] = {1, 2, 4, 8, 16};
	std::string str[] = {"orange", "apple", "raspberry"};
 
	// Create vector.
	std::vector<int> nums;
	nums.assign(arr, arr + 5);
	std::vector<std::string> fruits;
	fruits.assign(str, str + 3);
	std::vector<char> empty;
 
	// Print vector.
	std::cout << "nums: ";
	for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
		std::cout << *it << ' ' << std::endl;
 
	// Sums all integers in the vector nums (if any), printing only the result.
	std::cout << "Sum of nums: " << std::accumulate(nums.rbegin(), nums.rend(), 0) << std::endl;
 
	// Prints the first fruit in the vector fruits, checking if there is any.
	if (!fruits.empty())
	{
		std::cout << "First fruit: " << *fruits.rbegin() << std::endl;
	}

	if (empty.rbegin() == empty.rend())
	{
		std::cout << "vector 'empty' is indeed empty." << std::endl;
	}

	return (0);
}