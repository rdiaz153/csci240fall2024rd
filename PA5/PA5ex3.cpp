/*  Program: PA 5 EX 3
    Author: Ricardo Diaz
    Class: CSCI 240
    Date: 10/4/24
    Description: PA 5 Exercise 3
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include "linked_binary_tree.h"
#include <string>

using namespace std;
using namespace dsac::tree;

int main()
{
    cout << "Author: Ricardo Diaz" << endl;

    LinkedBinaryTree<string> tree;
    tree.add_root("A");
    tree.add_left(tree.root(), "B");
    tree.add_right(tree.root(), "C");
    tree.add_left(tree.root().left(), "D");
    tree.add_right(tree.root().left(), "E");
    tree.add_right(tree.root().right(), "F");

    cout << "Post-order traversal: ";
    auto positions = tree.positions();
    for (const auto& pos : positions) {
        cout << pos.element() << " ";
    }


    return 0;
}
