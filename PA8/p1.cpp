/*  Program: PA 8 Ex 1
    Author: Ricardo Diaz
    Class: CSCI 240
    Date: 10/28/24
    Description: PA 8 Exercise 1
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include "searchtree/tree_map.h"
#include <string>
#include <algorithm>

using namespace std;
using namespace dsac::search_tree;

string reverseKey(int key){
    string s = to_string(key);
    reverse(s.begin(), s.end());
    return s;
}

template<typename S, typename T>
void search(TreeMap<S, T>& tree_map, int key){
    auto it = tree_map.find(key);
    if(it != tree_map.end())
        cout << "Found: " << it->key() << " -> " << it->value() << endl;
    else
        cout << "Key " << key << " not found." << endl;
}

int main(){
    cout << "Author: Ricardo Diaz" << endl;
    TreeMap<int, string> tree_map;

    tree_map.put(10, reverseKey(10));
    tree_map.put(20, reverseKey(20));
    tree_map.put(4, reverseKey(4));
    tree_map.put(8, reverseKey(8));
    tree_map.put(15, reverseKey(15));
    tree_map.erase(8);
    tree_map.erase(10);

    search(tree_map, 15);
    search(tree_map, 30);
    search(tree_map, 8);

    for(auto it = tree_map.begin(); it != tree_map.end(); it++){
        cout << it->key() << " -> " << it->value() << endl;
    }
    // g++ p1.cpp -o p1.exe; ./p1.exe

    return 0;
}