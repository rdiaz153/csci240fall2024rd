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
#include <iomanip>
#include <vector>
#include "heap_priority_queue.h"
#include "linked_binary_tree.h"

using namespace std;
using namespace dsac::tree;
using namespace dsac::priority;

class HuffmanTree {
private:
    struct Node {
        char character;
        int frequency;
        LinkedBinaryTree<pair<char,int>> tree;

        Node(int c, char freq) : character(c), frequency(freq) {
            tree.add_root({c, freq});
        }

        Node(int freq, Node* left, Node* right) : character('*'), frequency(freq) {
            tree.add_root({'*', freq});
            tree.attach(tree.root(), left->tree, right->tree);
        }

        bool operator< (const Node& other) const {
            return frequency < other.frequency;
        }
    };

public:
    unordered_map<char, int> freqMap;
    string encodedBits;

    void createHuffmanTree(const string& text) {
        for (char c : text) {
            if (c == ' ') {
                c = '_';
            }
            freqMap[c]++;
        }

    
        HeapPriorityQueue<Node> pq;
    

        for (const auto& [character, frequency] : freqMap) {
            pq.insert(Node(character, frequency));
        }

        while (pq.size() > 1) {
            Node* left = new Node(pq.min());
            pq.remove_min();

            Node* right = new Node(pq.min());
            pq.remove_min();

            Node total(left->frequency + right->frequency, left, right);
            pq.insert(total);

            delete left;
            delete right;
        }

        Node root = pq.min();
        pq.remove_min();

        generateHCodes(root.tree, root.tree.root(), "");
        
        cout << "Text: \"" << text << endl;
        cout << "Number of characters: " << text.size() << endl;
        cout << "Huffman coding tree: " << endl;
        printHuffmanTree(root.tree, root.tree.root());

        this->root = root.tree.root();

        printHCodeTable(text);
    
    }

    void printHCodeTable(const string& text) {
        cout << endl << "Character frequency bits: " << endl;
        for (const auto& [character, encoding] : hCodes) {
            cout << character << "  " << freqMap[character] << "    " << encoding << endl;
        }

        int totalBits = 0;

        for (char c : text) {
            if (c == ' ') {
                c = '_';
            }
            encodedBits += hCodes[c];
            totalBits += hCodes[c].size();
        }
        cout << "Number of bits to encode message: " << totalBits << endl;
        cout << encodedBits << endl;
    }

    string decode(const string& encodedBits) {
        string decodedText = "";
        LinkedBinaryTree<pair<char, int>>::Position curNode = this->root;

        for (char bit : encodedBits) {
            if (bit == '0') {
                curNode = curNode.left();
            } else if (bit == '1') {
                curNode = curNode.right();
            }

            if (curNode.is_external()) {
                decodedText += curNode.element().first;
                curNode = this->root;
            }
        }
        return decodedText;
    }

private:
    unordered_map<char, string> hCodes;
    void generateHCodes(const LinkedBinaryTree<pair<char, int>>& tree, LinkedBinaryTree<pair<char, int>>::Position position, const string& code) {
        if (position.is_null()) {
            return;
        }
        if (position.left().is_null() && position.right().is_null()) {
            char character = position.element().first;
            hCodes[character] = code;
            return;
        }

        generateHCodes(tree, position.left(), code + "0");
        generateHCodes(tree, position.right(), code + "1");
    }

    void printHuffmanTree(const LinkedBinaryTree<pair<char, int>>& tree, LinkedBinaryTree<pair<char, int>>::Position position, int depth = 0) {
        if (position.is_null()) {
            return;
        }

        cout << string(depth * 4, ' ') << position.element().second << " " << position.element().first << endl;

        printHuffmanTree(tree, position.left(), depth + 1);
        printHuffmanTree(tree, position.right(), depth + 1);
    }

    LinkedBinaryTree<pair<char,int>>::Position root;
};

void testRun(string text) {
    HuffmanTree HM;
    HM.createHuffmanTree(text);

    string encodedBitsString = HM.encodedBits;

    string decodedText = HM.decode(encodedBitsString);
    cout << "Decoded Text: \"" << decodedText << "\"" << endl;
}

int main()
{
    cout << "Test" << endl;
    cout << "Author: Ricardo Diaz" << endl;
    cout << "Test case 1: " << endl;
    testRun("more money needed");

    cout << endl << "Test case 2: " << endl;
    testRun("aaabbb");


    // g++ p3.cpp -o p3.exe; ./p3.exe
    return 0;
}