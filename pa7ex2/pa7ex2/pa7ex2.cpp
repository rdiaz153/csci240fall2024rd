/*  Program: PA 7 Ex 2
    Author: Ricardo Diaz
    Class: CSCI 240
    Date: 10/18/24
    Description: PA 7 Exercise 2
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "chain_hash_map.h"

using namespace std;
using namespace dsac::map;

string reverseKey(int key) {
    string str = to_string(key);
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    ChainHashMap<int, string> map;

    int keys[] = { 13, 21, 5, 37, 15 };
    for (int key : keys) {
        map.put(key, reverseKey(key));
    }

    if (map.find(10) != map.end()) {
        cout << "Found: (10, " << map.at(10) << ").\n";
    }
    else {
        cout << "Not found\n";
    }
    if (map.find(21) != map.end()) {
        cout << "Found: (21, " << map.at(21) << ").\n";
    }
    else {
        cout << "Not found\n";
    }

    map.erase(20);
    map.erase(37);

    if (map.find(37) != map.end()) {
        cout << "Found: (37, " << map.at(37) << ").\n";
    }
    else {
        cout << "Not found\n";
    }

    return 0;
}
