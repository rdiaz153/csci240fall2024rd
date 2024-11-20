/*  Program: PA 10 Ex 1   
    Author: Ricardo Diaz    
    Class:  CSCI 240    
    Date:  11/18/24     
    Description: PA 10 Exercise 1
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>


using namespace std;

void partition(const vector<int>& S, int pivot, vector<int>& L, vector<int>& E, vector<int>& G, int& comparisons) {
    for (int num : S) {
        comparisons++;
        if (num < pivot) {
            L.push_back(num);
        } else if (num == pivot) {
            E.push_back(num);
        } else {
            G.push_back(num);
        }
    }
}

int quickSelect(vector<int>& S, int k, int& comparisons) {
    if (S.size() == 1) 
    {
        return S[0];
    }

    int pivotIndex = rand() % S.size();
    int pivot = S[pivotIndex];

    vector<int> L, E, G;
    partition(S, pivot, L, E, G, comparisons);

    if (k <= L.size()) {
        return quickSelect(L, k, comparisons);
    } else if (k <= L.size() + E.size()) {
        return pivot;
    } else {
        return quickSelect(G, k - L.size() - E.size(), comparisons);
    }


}

int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    srand(time(0));

    vector<int> small = {12, 7, 5, 3, 19, 2, 1, 13, 16, 9};
    vector<int> Ks = {1, static_cast<int>(small.size() / 2), static_cast<int>(small.size())};

    cout << "Small Array Test:\n";
    for (int k : Ks) {
        auto start = chrono::high_resolution_clock::now();

        int comparisons = 0;
        int kthSmallest = quickSelect(small, k, comparisons);

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "k = " << k << ": " << kthSmallest << ", Comparisons: " << comparisons;
        cout << ", Time: " << elapsed << " ms" << endl;
    }

    vector<string> filenames = {"small1k.txt", "large100k.txt"};
    for (const string& filename : filenames) {
        ifstream file(filename);
        vector<int> data;
        int num;
        while (file >> num) {
            data.push_back(num);
        }

        auto start = chrono::high_resolution_clock::now();

        int comparisons = 0;
        int median = quickSelect(data, data.size() / 2, comparisons);

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "File: " << filename << " Median: " << median << ", Comparisons: " << comparisons << endl;
        cout << "Time: " << elapsed << " ms" << endl;
    }
    return 0;
    // g++ p1.cpp -o p1.exe; ./p1.exe
}
