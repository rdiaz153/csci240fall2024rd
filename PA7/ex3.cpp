/*  Program: PA 7 Ex 3
    Author: Ricardo Diaz
    Class: CSCI 240
    Date: 10/20/24
    Description: PA 7 Exercise 3
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

int polyHash(const string& s, int a) {
    int hash = 0;
    for (char c : s) {
        hash = hash * a + static_cast<int>(c);
    }
    return hash;
}

int cyclicHash(const string& s, int shift) {
    const int U_INT_BITS{ std::numeric_limits<unsigned int>::digits };
    unsigned int h{ 0 };
    for (char c : s) {
        h = (h << shift) | (h >> (U_INT_BITS - shift));
        h += c;
    }
    int h1 = int(h);
    return h1 < 0 ? -h1 : h1;
}

void process(const string& filename, int m) {
    ifstream inFile(filename);
    unordered_set<string> unique_words;
    unordered_map<int, string> map;

    string word;
    int a_values[] = { 1,37,40,41 };
    int shift_values[] = { 0, 1, 5, 13 };

    while (inFile >> word) {
        unique_words.insert(word);
    }
    inFile.close();

    cout << "Number of unique words: " << unique_words.size() << endl;

    if (m == 1) {
        for (int a : a_values) {
            int collisions = 0;
            map.clear();

            for (const string& word : unique_words) {
                int hash = polyHash(word, a);
                if (map.find(hash) != map.end() && map[hash] != word) {
                    collisions++;
                }
                map[hash] = word;
            }
            cout << "Collisions for a = " << a << ": " << collisions << endl;
        }
    } else if (m == 2) {
        for (int shift : shift_values) {
            int collisions = 0;
            map.clear();
               
            for (const string& word : unique_words) {
                int hash = cyclicHash(word, shift);
                if (map.find(hash) != map.end() && map[hash] != word) {
                    collisions++;
                }
                map[hash] = word;
            }
            cout << "Collisions for shift = " << shift << ": " << collisions << endl;
        }
    }
}


int main()
{
    cout << "Author: Ricardo Diaz" << endl;

    cout << "Analyzing collisions using polynomial hash function: \n";
    process("USDeclIndFormatted.txt", 1);

    cout << "Analyzing collisions using cyclic shift hash function: \n";
    process("USDeclIndFormatted.txt", 2);


    return 0;
}
