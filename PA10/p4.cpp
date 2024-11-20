/*  Program: PA10 Ex 4  
    Author:  Ricardo Diaz   
    Class:  CSCI240    
    Date: 11/18/24     
    Description: PA10 Exercise 4
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>


using namespace std;

vector<vector<int>> matrix_chain(const vector<int>& d) {
    int n = d.size() - 1;                                       // number of matrices
    vector<vector<int>> N(n, vector<int>(n, 0));                // n-by-n matrix; initially zeros
    for (int b = 1; b < n; b++)                                 // number of products in subchain
        for (int i = 0; i < n - b; i++) {                       // start of subchain
            int j{i + b};                                       // end of subchain
            N[i][j] = numeric_limits<int>::max();               // used as 'infinity'
            for (int k = i; k < j; k++)
                N[i][j] = min(N[i][j], N[i][k] + N[k + 1][j] + d[i]*d[k + 1]*d[j + 1]);
        }
    return N;
}

void printTable(const vector<vector<int>>& table) {
    int n = table.size();
    cout << "Final Table: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                cout << setw(8) << "-";
            } else {
                cout << setw(8) << table[i][j];
            }
        }
        cout << endl;
    }
}

int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    vector<int> dims1 = {2, 10, 50, 20};
    vector<vector<int>> table1 = matrix_chain(dims1);

    cout << "Test case 1: B * C * D (Dimensions: 2x10, 10x50, 50x20)" << endl;
    cout << "Minimum # of operations: " << table1[0][dims1.size() - 2] << endl;
    printTable(table1);
    
    vector<int> dims2 = {10, 5, 2, 20, 12, 4, 60};
    vector<vector<int>> table2 = matrix_chain(dims2);

    cout << "Test case 2: A * B * C * D * E * F (Dimensions: 10x5, 5x2, 2x20, 20x12, 12x4, 4x60)" << endl;
    cout << "Minimum # of operations: " << table2[0][dims2.size() - 2] << endl;
    printTable(table2);

    return 0;
}