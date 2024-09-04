/*  Program:    PA 1 Extra Credit 1
    Author:     Ricardo Diaz
    Class:      CSCI 240 
    Date:       8/22/24
    Description: Review Basic C++/Java & OOP.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
// create random index(?)
//if-else or switch?
//remove or insert or replace a char

string createMistake(string& sentence){
  string result = sentence;
  int len = sentence.length();
  int mistake_type = rand() % 3;

  switch (mistake_type) {
    case 0: {
      int pos = rand() % len;
      result[pos] = 'a' + rand() % 26;
      break;
    }
    case 1: {
      int pos = rand() % len;
      result.erase(pos, 1);
      break;
    }
    case 2: {
      int pos = rand() % len;
      result.insert(pos, 1, 'a' + rand() % 26);
      break;
    }
  }
  return result;
}

int main() {

  srand(time(0));

  string sentence = "I will always use object-oriented design.";

  for (int i = 1; i <= 50; i++) {
    string output = sentence;
    int numMistakes = 0;

    while (numMistakes < 8) {
      output = createMistake(output);
      numMistakes++;
    }

    cout << i << ": " << output << std::endl;
  }

  return 0;
}