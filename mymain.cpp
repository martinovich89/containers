#include "vector.hpp"
//#include "map.hpp"
#include "pair.hpp"

// test vector and iterator classes
int main()
{
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;

	// set some values:
	for (int i=1; i<=5; i++) myvector.push_back(i); // myvector: 1 2 3 4 5

	it = myvector.begin();
	++it;       // "it" points now to number 2           ^

	myvector.insert (it,10);                        // myvector: 1 10 2 3 4 5

	// "it" still points to number 2                      ^
	myvector.insert (it,2,20);                      // myvector: 1 10 20 20 2 3 4 5

	--it;       // "it" points now to the second 20            ^

	std::vector<int> myvector2 (2,30);
	myvector.insert (it,myvector2.begin(),myvector2.end());
	// myvector: 1 10 20 30 30 20 2 3 4 5
	// "it" no longer valid, get a new one:
	it = myvector.begin();

	it += 3;    // "it" points now to number 30                ^

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

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;	

	return 0;
}