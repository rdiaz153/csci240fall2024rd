/*  Program: PA 4 EC 1
    Author: Ricardo Diaz
    Class: CSCI 240
    Date: 9/29/24
    Description: PA 4 Extra Credit 1
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class MyArrayStack {
private:
    T arr[10];
    int topIndex;

public:
    MyArrayStack() : topIndex(-1) {}

    int size() const {
        return topIndex + 1;
    }

    bool empty() const {
        return topIndex == -1;
    }

    T top() const {
        if (!empty()) {
            return arr[topIndex];
        } else {
            return -1;
        }
    }

    void push(T e) {
        arr[++topIndex] = e;
    }

    T pop() {
        if (!empty()) {
            return arr[topIndex--];
        } else {
            return -1;
        }
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string inFixtoPostFix(const string& s1) {
    MyArrayStack<char> stack;
    string result;
    istringstream iss(s1);
    string token;

    while (iss >> token) {
        char c = token[0];
        if (isdigit(c) || (token.size() > 1 && c == '-')) {
            result += token + " ";
        } 
        else if (c == '(') {
            stack.push(c);
        } 
        else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                result += stack.pop();
                result += " ";
            }
            stack.pop();
        }
        else {
            while (!stack.empty() && precedence(stack.top()) >= precedence(c)) {
                result += stack.pop();
                result += " ";
            }
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        result += stack.pop();
        result += " ";
    }
    return result;
}


int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    string string1 = "17 / ( 2 + 3 ) - 13";
    string string2 = "5 * ( 2 + 3 )";
    string string3 = "2 * ( 3 / 2 )";
    string string4 = "( -23 + 123 ) * 2";

    cout << "Result of the first string: " << inFixtoPostFix(string1) << endl;
    cout << "Result of the second string: " << inFixtoPostFix(string2) << endl;
    cout << "Result of the third string: " << inFixtoPostFix(string3) << endl;
    cout << "Result of the fourth string: " << inFixtoPostFix(string4) << endl;

    return 0;
}
