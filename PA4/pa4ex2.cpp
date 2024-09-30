/*  Program: PA 4 EX 2
    Author: Ricardo Diaz
    Class: CSCI 240
    Date: 9/29/24
    Description: PA 4 Exercise 2
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

int evaluatePostFix (const string& s1) {
    MyArrayStack<int> stack;
    istringstream iss(s1);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            stack.push(stoi(token));
        } else {
            int op2 = stack.pop();
            int op1 = stack.pop();

            if (token == "+") {
                stack.push(op1 + op2);
            } else if (token == "-") {
                stack.push(op1 - op2);
            } else if (token == "*") {
                stack.push(op1 * op2);
            } else if (token == "/") {
                stack.push(op1 / op2);
            }
        }

    }
    return stack.top();

}
int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    string string1 = "17 2 3 + / 13 -";
    string string2 = "5 2 3 + *";
    string string3 = "2 3 2 / *";
    string string4 = "-23 123 + 2 *";

    cout << "Result of the first string: " << evaluatePostFix(string1) << endl;
    cout << "Result of the second string: " << evaluatePostFix(string2) << endl;
    cout << "Result of the third string: " << evaluatePostFix(string3) << endl;
    cout << "Result of the fourth string: " << evaluatePostFix(string4) << endl;

    return 0;
}
