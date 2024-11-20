/*  Program: PA10 Ex 3   
    Author: Ricardo Diaz    
    Class:  CSCI 240    
    Date: 11/18/24      
    Description: PA10 Exercise 3
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include "heap_priority_queue.h"
#include "linked_binary_tree.h"

using namespace std;
using namespace dsac::tree;
using namespace dsac::priority;

class HuffmanTree {
public:
    char character;
    int frequency;
    HuffmanTree* left;
    HuffmanTree* right;

    HuffmanTree(char c, int freq, HuffmanTree* l = nullptr, HuffmanTree* r = nullptr) : character(c), frequency(freq), left(l), right(r) {}

    HuffmanTree(int freq, HuffmanTree* l, HuffmanTree* r) : character('\0'), frequency(freq), left(l), right(r) {}
    
};
    struct Compare {
        bool operator()(HuffmanTree* a, HuffmanTree* b) {
            return a->frequency > b->frequency;
        }
    };

    HuffmanTree* buildHuffmanTree(const string& text) {
        unordered_map<char, int> freqMap;
        for (char c : text) {
            freqMap[c]++;
        }

        HeapPriorityQueue<HuffmanTree*, Compare> pq;
        for (const auto& iter : freqMap) {
            pq.insert(new HuffmanTree(iter.first, iter.second));
        }

        while (pq.size() > 1) {
            HuffmanTree* left = pq.min();
            pq.remove_min();
            HuffmanTree* right = pq.min();
            pq.remove_min();

            HuffmanTree* parent = new HuffmanTree(left->frequency + right->frequency, left, right);
            pq.insert(parent);
        }

        return pq.min();
    }

    void printHuffmanTree(HuffmanTree* root, int depth = 0) {
        if (!root) {
            return;
        }

        cout << string(depth * 2, ' ');
        if (root->character == ' ') {
            cout << "_" << "< -- this is a space\n";
        } else {
            cout << root->character << endl;
        }

        printHuffmanTree(root->left, depth + 1);
        printHuffmanTree(root->right, depth + 1);
    }

int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    HuffmanTree* root = buildHuffmanTree(text);

    cout << "Text: \"" << text <<"\"" << endl;
    cout << "number of characters: " << text.length() << endl;

    cout << "Huffman coding tree: " << endl;
    printHuffmanTree(root);

    // g++ p3.cpp -o p3.exe; ./p3.exe
    return 0;
}