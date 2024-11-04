/*  Program: PA8 Ex 3
    Author: Ricardo Diaz
    Class:  CSCI 240    
    Date: 10/28/24     
    Description: PA 8 Exercise 3
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include "searchtree/avl_tree_map.h"
#include <string>
#include <algorithm>

using namespace std;
using namespace dsac::search_tree;

string reverseKey(int key) {
    string s = to_string(key);
    reverse(s.begin(), s.end());
    return s;
}

template<typename S, typename T>
void search(TreeMap<S, T>& treeMap, int key) {
    auto it = treeMap.find(key);
    if (it != treeMap.end()) {
        cout << "Found: " << it->key() << " -> " << it->value() << endl;
    } else {
        cout << "Key " << key << " not found." << endl;
    }
    
}

void printTree(AVLTreeMap<int, string>& map); 

int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    AVLTreeMap<int, string> map;

    map.put(10, reverseKey(10));
    map.put(20, reverseKey(20));
    map.put(4, reverseKey(4));
    map.put(8, reverseKey(8));
    map.put(15, reverseKey(15));
    map.erase(8);
    map.erase(10);

    map._dump();

    auto search15 = map.find(15);
    auto search30 = map.find(30);
    auto search8 = map.find(8);

    for (auto it = map.begin(); it != map.end(); ++it) {
        cout << it->key() << " -> " << it->value() << " Height: " << map.height(it->key()) << endl;
    }

    return 0;
}
