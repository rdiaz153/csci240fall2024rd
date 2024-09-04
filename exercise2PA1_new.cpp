/*  Program:    PA 1 Exercise 2
    Author:     Ricardo Diaz
    Class:      CSCI 240
    Date:       8/22/24
    Description: Review Basic C++/Java & OOP.
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Hint: use a triple nested loop, # of people (5, 10, 15, ...), # of experiments, process # of people, call function/method from exercise 1 //

// function from exercise 1
int duplicateValues(vector<int> a, int size) {
    int count = 0;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] == a[j])
                count++;
        }
    }
    return count;
}

int main() {

    srand(time(0));
    const int experiments = 100;

    for (int n = 5; n <= 100; n += 5) {
        int count = 0;

        for (int i = 0; i < experiments; i++) {
            vector<int> birthdays;
            for (int j = 0; j < n; j++) {
                birthdays[j] = rand() % 365 + 1;
            }

            if (duplicateValues(birthdays, n) > 0) {
                count++;
            }
        }

        cout << n << "\t" << count << " out of " << experiments << endl;
    }


    return 0;
}