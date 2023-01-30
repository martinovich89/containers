#ifdef __STL__
# include <vector>
# include <map>
namespace ft = std;
# define VECTOR_NAME "stlvector"
#else
# include "vector.hpp"
# include "map.hpp"
# define VECTOR_NAME "ftvector"
#endif
#include <iostream>
#include <string>
//#include <algorithm>
#include <numeric>

//#include "vector.hpp"
//#include "map.hpp"
//#include "pair.hpp"

int main(void)
{
    //Create a map with default constructor
    ft::map<int, int> mymap;

    // Insert some elements
    mymap.insert(ft::pair<const int, int>(1, 10));
    mymap.insert(ft::pair<const int, int>(2, 20));
    mymap.insert(ft::pair<const int, int>(3, 30));
    mymap.insert(ft::pair<const int, int>(4, 40));
    mymap.insert(ft::pair<const int, int>(5, 50));
    mymap.insert(ft::pair<const int, int>(6, 60));
    mymap.insert(ft::pair<const int, int>(7, 70));
    mymap.insert(ft::pair<const int, int>(8, 80));
    mymap.insert(ft::pair<const int, int>(9, 90));

    // print out content:
    std::cout << "mymap contains:" << std::endl;
    for (ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    // erase the first 3 elements:
    for (int i = 1; i < 4; i++)
        mymap.erase(i);

    // print out content:
    std::cout << "mymap contains:" << std::endl;
    for (ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    

    return (0);
}