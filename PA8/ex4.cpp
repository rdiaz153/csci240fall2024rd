/*  Program: PA 8 Ex 4   
    Author: Ricardo Diaz   
    Class: CSCI 240     
    Date: 10/28/24     
    Description: PA 8 Exercise 4
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include "searchtree/avl_tree_map.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
using namespace dsac::search_tree;

class BetterPopMap {
private:
    AVLTreeMap<int, string> map;

public:
    BetterPopMap(const string& filename) {
        ifstream file(filename);
        string line;

        while (getline(file, line)) {
            stringstream ss(line);
            int code;
            string popRec;

            getline(ss, popRec, ',');
            code = stoi(popRec);

            getline(ss, popRec);
            map.put(code, popRec);
        }
        file.close();
    }

    void find(int code) {
        auto result = map.find(code);
        if (result != map.end()) {
            cout << "Found: " << code << " -> " << result->value() << endl;
        } else {
            cout << "No record with code " << code << " found." << endl;
        }
    }

    void insert(int code, const string& popCounty) {
        auto result = map.find(code);
        if (result != map.end()) {
            cout << "Inserted/Updated: " << code << " -> " << popCounty << endl;
        }
    }

    void erase(int code) {
        auto result = map.find(code);
        if (result != map.end()) {
            cout << "Deleting: " << code << endl;
            map.erase(result);
        } else {
            cout << "Code " << code << " not found." << endl;
        }
    }

    void print() {
        
    }
};

int main() {
    cout << "Author: Ricardo Diaz" << endl;


}