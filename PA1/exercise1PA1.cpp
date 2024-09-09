/*  Program:    PA 1 Exercise 1
    Author:     Ricardo Diaz
    Class:      CSCI 240 
    Date:       8/22/24
    Description: Review Basic C++/Java & OOP.
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>

using namespace std;

int duplicateValues (int a[], int size) {
  int count = 0;

  for (int i = 0; i < size; i++)
  {
      for (int j = i + 1; j < size; j++) 
      {
          if (a[i] == a[j])
          count++;
      }
  }
  return count;
}

int main()
{
    cout << "Author: Ricardo Diaz" << endl;

    int testSize1[] = {5, 7, 2, 6, 4};
    int testSize2[] = {5, 7, 2, 2, 5, 6, 4, 2};

    int size1 = sizeof(testSize1) / sizeof(int);
    int size2 = sizeof(testSize2) / sizeof(int);

    cout << "The number of duplicate values in the first array is " << duplicateValues(testSize1, size1) << "." << endl;
    cout << "The number of duplicate values in the second array is " << duplicateValues(testSize2, size2) << "." << endl;

    


    return 0;
}