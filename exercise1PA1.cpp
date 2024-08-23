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

    int size1 = sizeof(testSize1);

    cout << size1;


    return 0;
}