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

    int height(TreeMap<int, string>::Node* node) const {
        if (node == nullptr) {
            return -1;
        }
        return 1 + max(height(node->left), height(node->right));
    }
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
        cout << "Tree height: " << height(treeMap.) << endl;
    }

    void find(int code) {
        if (auto it != treeMap.end()) {
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

    int height() const {
        if (treeMap)
    }

};

int main()
{
    cout << "Author: Ricardo Diaz" << endl;

    return 0;
}
