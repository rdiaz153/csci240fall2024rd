/*  Program: PA 8 Ex 2   
    Author: Ricardo Diaz   
    Class: CSCI 240     
    Date: 10/28/24     
    Description: PA 8 Exercise 2
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "searchtree/tree_map.h"

using namespace std;
using namespace dsac::search_tree;

class SimplePopMap {
private:
    TreeMap<int, string> treeMap;

public:
    SimplePopMap(const string& filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            istringstream ss(line);
            string codeStr, value;
            getline(ss, codeStr, ',');
            getline(ss, value);
            int code = stoi(codeStr);
            treeMap.put(code, value);
        }
        cout << "Tree height: " << treeMap.height() << endl;
    }

    void find(int code) {
        auto it = treeMap.find(code);
        if (it != treeMap.end()) {
            cout << "Found: " << code << "-> " << it->value() << endl;
        } else {
            cout << "Code " << code << " not found." << endl;
        }
    }

    void insert(int code, const std::string& popCounty) {
        auto it = treeMap.put(code, popCounty);
        if (it != treeMap.end()) {
            cout << "Inserted/Updated: " << code << "-> " << popCounty << endl;
        }
    }

    void erase(int code) {
        auto it = treeMap.find(code);
        if (it != treeMap.end()) {
            treeMap.erase(it);
            cout << "Erased code " << code << endl;
        } else {
            cout << "Code " << code << "not found for erasure." << endl;
        }
    }

    void print() {
        cout << "Tree height: " << treeMap.height() << endl;
        for (auto it = treeMap.begin(); it != treeMap.end(); ++it) {
            cout << it->key() << ": " << it->value() << endl;
        }
    }

};

int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    SimplePopMap map("popSmall.txt");
    map.print();
    map.find(6037);
    map.find(6000);
    map.insert(6066, "1, New County, CA");
    map.insert(6065, "2000, Riverside, CA");
    map.erase(6999);
    map.erase(6075);
    map.erase(6055);
    map.print();

    // g++ ex2.cpp -o ex2.exe; ./ex2.exe
    return 0;
}
