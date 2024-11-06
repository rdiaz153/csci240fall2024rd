/*  Program: PA9 Ex 3   
    Author:  Ricardo Diaz   
    Class: CSCI240      
    Date: PA9 Exercise 3      
    Description: 
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <chrono>
#include <fstream>
#include "quicksort.h"

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
    cout << "Author: Ricardo Diaz" << endl;
    vector<int> data = {4, 3, 1, 0, 9, 8, 6, 7, 5, 2};
    comparisons = 0;
    dataMoves = 0;
    
    cout << "Original small list: ";
    for (int val : data) {
        cout << val << " ";
    }
    cout << endl;

    quick_sort_in_place(data, less<int>());

    cout << "Sorted small list: ";
    for (int val : data) {
        cout << val << " ";
    }

    cout << "\nComparisons: " << comparisons << " Data Moves: " << dataMoves << endl;

    vector<int> small1k = readData("small1k.txt");
    vector<int> large100k = readData("large100k.txt");

    comparisons = 0;
    dataMoves = 0;
    auto start = chrono::high_resolution_clock::now();
    quick_sort_in_place(small1k, less<int>());
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "small1k.txt details: " << endl;
    printDetails(small1k);
    cout << "Comparisons: " << comparisons << " Data Moves: " << dataMoves;
    cout << " Time: " << elapsed << " milliseconds." << endl;

    comparisons = 0;
    dataMoves = 0;
    auto start2 = chrono::high_resolution_clock::now();
    quick_sort_in_place(large100k, less<int>());
    auto end2 = chrono::high_resolution_clock::now();
    auto elapsed2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();

    cout << "large100k.txt details: " << endl;
    printDetails(large100k);
    cout << "Comparisons: " << comparisons << " Data Moves: " << dataMoves;
    cout << " Time: " << elapsed2 << " milliseconds." << endl;

    // g++ ex3.cpp -o ex3.exe; ./ex3.exe
    return 0;
}