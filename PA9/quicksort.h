#pragma once

#include <algorithm>       // defines std::min
#include <list>
#include <vector>

int comparisons = 0;
int dataMoves = 0;

namespace dsac::sorting {

template <typename T>
T medianOf3(std::vector<T>& a, int low, int high) {
    int mid = low + (high - low) / 2;

    if (a[high] < a[low]) 
        std::swap(a[low], a[high]);
    if(a[mid] < a[low])
        std::swap(a[low], a[mid]);
    if(a[high] < a[mid])
        std::swap(a[mid], a[high]);

    return mid;
}

/// Sorts the contents of vector S using the given comparator to define the element ordering
template <typename T, typename Compare>
void quick_sort(std::list<T>& S, Compare comp) {
    int n(S.size());
    if (n < 2) return;                                       // list is trivially sorted

    // divide
    T pivot = S.back();
    std::list<T> L,E,G;                                      // three empty lists
    for (T element : S) {
        if (comp(element, pivot))                            // element strictly less than pivot
            L.push_back(element);
        else if (comp(pivot, element))                       // element strictly greater than pivot
            G.push_back(element);
        else                                                 // element is equal to pivot
            E.push_back(element);
    }

    // conquer
    quick_sort(L, comp);
    quick_sort(G, comp);

    // concatenate results back into S
    S.clear();
    for (T elem : L)
        S.push_back(elem);
    for (T elem : E)
        S.push_back(elem);
    for (T elem : G)
        S.push_back(elem);
}

template <typename T, typename Compare>
void quick_sort_in_place(std::vector<T>& S, Compare comp, int a, int b) {
    if (a >= b) return;                        // subarray is trivially sorted
    int mid = a + (b - a) / 2;
    int pivotIndex = medianOf3(S, a, b);
    std::swap(S[pivotIndex], S[b]);
    dataMoves++; 

    T pivot{S[b]};
    int left{a};
    int right{b - 1};
    while (left <= right) {
        // scan until reaching value equal or larger than pivot (or right marker)
        while (left <= right && comp(S[left], pivot)) {
            left++;
            comparisons++;
        }
        // scan until reaching value equal or smaller than pivot (or left marker)
        while (left <= right && comp(pivot, S[right])) { 
            right--;
        }
        if (left <= right) {                   // indices did not strictly cross
            // so swap values and shrink range
            std::swap(S[left], S[right]);
            left++; right--;
            dataMoves += 2;
        }
    }
    // put pivot into its final place (currently marked by left index)
    std::swap(S[left], S[b]);
    dataMoves++;

    // make recursive calls
    quick_sort_in_place(S, comp, a, left - 1);
    quick_sort_in_place(S, comp, left + 1, b);
    
}

// version without extraneous arguments
template <typename T, typename Compare>
void quick_sort_in_place(std::vector<T>& S, Compare comp) {
    quick_sort_in_place(S, comp, 0, S.size() - 1);
}

// versions that use std::less as default comparator
 
template <typename T>
void quick_sort(std::vector<T>& S) { quick_sort(S, std::less<T>()); }
    
template <typename T>
void quick_sort_in_place(std::list<T>& S) { quick_sort_in_place(S, std::less<T>()); }
    


 
} // namespace dsac::sorting
    
