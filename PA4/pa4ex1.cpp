/*  Program: PA4 EX1
    Author: Ricardo Diaz
    Class: CSCI 240
    Date: 9/29/24  
    Description: PA 4 Exercise 1
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool checkBalanced (char c1, char c2) {
    return (c1 == '(' && c2 == ')') || 
    (c1 == '[' && c2 == ']') || 
    (c1 == '{' && c2 == '}');
}

string processSymbols(string s1) {
    stack<char> s;
    for (char ch : s1) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return "Invalid, no matching opening symbol.";
            } else if (!checkBalanced(s.top(), ch)) {
                return "Invalid, closing symbol does not match opening symbol.";
            } else {
                s.pop();
            }
        }
    } 
    return "Valid.";
}

int main()
{
    cout << "Author: Ricardo Diaz" << endl;
    string string1 = "{ ( a + b ) * c1 }";
    string string2 = "{ ( a + b ) * c1 ]";
    string string3 = "( ( a + b ) * c1 ) / 15 )";
    string string4 = "( ( ( a + b ) * c1 ) / 15 )";

    cout << string1 << " - " << processSymbols(string1) << endl;
    cout << string2 << " - " << processSymbols(string2) << endl;
    cout << string3 << " - " << processSymbols(string3) << endl;
    cout << string4 << " - " << processSymbols(string4) << endl;
    return 0;
}