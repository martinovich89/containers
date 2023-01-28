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

    // print out content:
    std::cout << "mymap contains:" << std::endl;
    for (ft::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    

    return (0);
}