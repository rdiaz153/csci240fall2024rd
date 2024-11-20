/*  Program: PA9 Ex 1
    Author: Ricardo Diaz
    Class: CSCI240     
    Date: 11/3/24
    Description: PA9 Exercise 1
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <chrono>
#include <fstream>
#include <algorithm>

using namespace std;

int comparisons = 0;
int dataMoves = 0;
// ask if this insertionSort is supposed to sort in descending order?
void insertionSort(int array[], int size)
{
    comparisons = 0;
    dataMoves = 0;
    int scan, unsortedValue;
    
    for (int index = 1; index < size; index++)
    {
        unsortedValue = array[index];
        scan = index;
        dataMoves++;
        while (scan > 0)
        {
            comparisons++;
            if (array[scan - 1] > unsortedValue)
                break;
            array[scan] = array[scan - 1];
            dataMoves++;
            scan--;
        }

        array[scan] = unsortedValue;
        dataMoves++;
    }
}

int countInversions(int array[], int size)
{
    int numInversions = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        if (array[i] > array[j]) {
            numInversions++;
        }
    }
    return numInversions;
}

int printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i) 
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    int smallArr[] = {4, 3, 1, 0, 9, 8, 6, 7, 5, 2};
    int size = 10;

    cout << "Original small array: ";
    printArray(smallArr, size);

    int smallInversions = countInversions(smallArr, size);

    insertionSort(smallArr, size);
    cout << "Sorted small array: ";
    printArray(smallArr, size);

    cout << "Inversions: " << smallInversions << " Comparisons: " << comparisons << " Data Moves: " << dataMoves << endl;

    // for the sorted list, sort it again and output the number of inversions
    // number of comparisons, and data moves.
    int smallInversions2 = countInversions(smallArr, size);
    insertionSort(smallArr, size);
    cout << "Sorted small array (again): ";
    printArray(smallArr, size);
    cout << "Inversions: " << smallInversions2 << " Comparisons: " << comparisons << " Data Moves: " << dataMoves << endl << endl;

    // reverse the sorted list, sort it again, output everything again
    reverse(smallArr, smallArr + size);
    int smallInversions3 = countInversions(smallArr, size);
    insertionSort(smallArr, size);

    cout << "Sorted reversed list: ";
    printArray(smallArr, size);
    cout << "Inversions: " << smallInversions3 << " Comparisons: " << comparisons << " Data Moves: " << dataMoves << endl << endl;
    
    int largeList[1000];
    ifstream inputFile("small1k.txt");
    for (int i = 0; i < 1000; ++i) {
        inputFile >> largeList[i];
    }
    inputFile.close();

    cout << "Random order 1k list: " << endl << endl;

    int numInversions = countInversions(largeList, 1000);
    auto start = chrono::high_resolution_clock::now();
    insertionSort(largeList, 1000);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start).count();
    
    cout << "First 5 values of the 1,000 list: ";
    for (int i = 0; i < 5; ++i) {
        cout << largeList[i] << " ";
    }
    cout << endl;

    cout << "Last 5 values of the 1,000 list: ";
    for (int i = 995; i < 1000; ++i) {
        cout << largeList[i] << " ";
    }
    cout << endl;

    cout << "Inversions: " << numInversions << " Comparisons: " << comparisons << " Data Moves: " << dataMoves << endl;
    cout << "Time: " << elapsed << " µs." << endl;

    cout << "Sorted 1k list: " << endl << endl;

    int numInversions2 = countInversions(largeList, 1000);
    auto start2 = chrono::high_resolution_clock::now();
    insertionSort(largeList, 1000);
    auto end2 = chrono::high_resolution_clock::now();
    auto elapsed2 = chrono::duration_cast<chrono::microseconds>(end2 - start2).count();
    
    cout << "First 5 values of the 1,000 list: ";
    for (int i = 0; i < 5; ++i) {
        cout << largeList[i] << " ";
    }
    cout << endl;

    cout << "Last 5 values of the 1,000 list: ";
    for (int i = 995; i < 1000; ++i) {
        cout << largeList[i] << " ";
    }
    cout << endl;

    cout << "Inversions: " << numInversions2 << " Comparisons: " << comparisons << " Data Moves: " << dataMoves << endl;
    cout << "Time: " << elapsed2 << " µs." << endl;


    // g++ ex1.cpp -o ex1.exe; ./ex1.exe
    return 0;
}
