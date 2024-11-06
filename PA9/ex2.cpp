/*  Program: PA9 Ex 2   
    Author: Ricardo Diaz   
    Class: CSCI240    
    Date: 11/6/24   
    Description: PA9 Exercise 2
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include "mergesort.h"
#include <string>

using namespace std;
using namespace dsac::sorting;

vector<int> readData(const string& filename) {
    vector<int> data;
    ifstream file(filename);
    int value;
    while (file >> value) {
        data.push_back(value);
    }
    return data;
}

void printDetails(const vector<int>& data) {
    cout << "First 5 values: ";
    for (int i = 0; i < 5; ++i) {
        cout << data[i] << " ";
    }
    cout << "\nLast 5 values: ";
    for (int i = data.size() - 5; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Author: Ricardo Diaz " << endl;
    vector<int> data = {4, 3, 1, 0, 9, 8, 6, 7, 5, 2};

    comparisons = 0;
    dataMoves = 0;

    cout << "Original list: ";
    for (int val : data) {
        cout << val << " ";
    }

    merge_sort_bottom_up(data, less<int>());

    cout << "Sorted list: ";
    for (int val : data) {
        cout << val << " ";
    }
    cout << endl << "Comparisons: " << comparisons << " Data Moves: " << dataMoves << endl;

    vector<int> small1k = readData("small1k.txt");
    vector<int> large100k = readData("large100k.txt");

    comparisons = 0;
    dataMoves = 0;
    auto start = chrono::high_resolution_clock::now();
    merge_sort_bottom_up(small1k, less<int>());
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << endl << "small1k.txt details:" << endl;
    printDetails(small1k);
    cout << "Comparisons: " << comparisons << " Data Moves: " << dataMoves;
    cout << " Time: " << elapsed << " microseconds." << endl;

    comparisons = 0;
    dataMoves = 0;
    auto start2 = chrono::high_resolution_clock::now();
    merge_sort_bottom_up(large100k, less<int>());
    auto end2 = chrono::high_resolution_clock::now();
    auto elapsed2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();

    cout << endl << "large100k.txt details:" << endl;
    printDetails(large100k);
    cout << "Comparisons: " << comparisons << " Data Moves: " << dataMoves;
    cout << " Time: " << elapsed2 << " milliseconds." << endl;
 


    // g++ ex2.cpp -o ex2.exe; ./ex2.exe
    return 0;
}


