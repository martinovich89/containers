#include <iostream>
#include <algorithm>
#include "rbtree.hpp"

int main(void)
{
    // Create an Rbtree with default constructor
    ft::Rbtree<int> mytree;

    // Insert some elements
    mytree.add_node(10);
    mytree.add_node(20);
    mytree.add_node(5);
    mytree.add_node(15);
    mytree.add_node(25);
    mytree.add_node(30);
    mytree.add_node(35);

    // make iterator point to the first element
    ft::Rbtree<int>::iterator it = mytree.begin();

    // Print the first element
    std::cout << "The first element is: " << *it << std::endl;

    // Print the tree
    std::cout << "mytree contains:";
    for (ft::Rbtree<int>::iterator it1 = mytree.begin(); it1 != mytree.end(); ++it1)
        std::cout << ' ' << *it1;
    std::cout << std::endl;

    mytree.delete_node(10);
    mytree.delete_node(20);

    // Print the tree
    std::cout << "mytree contains:";
    for (ft::Rbtree<int>::iterator it1 = mytree.begin(); it1 != mytree.end(); ++it1)
        std::cout << ' ' << *it1;
    std::cout << std::endl;
    
}