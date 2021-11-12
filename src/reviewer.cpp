#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> grabWords(string input) {
    vector<string> result;
    string temp;
    for (int i = 0; i < input.length(); i ++) {
      char c = input[i];
      if (c == ' ' || c == '\t' || c == '\n') {
          if (temp.length() > 0) {
            result.push_back(temp);
            temp = string();
          }else {
            temp += c;
          }
      }
    } 
    if (temp.length() > 0) {
      result.push_back(temp);
    }
    return result;
}

int main() { 
  cout << "Book reviewer" << endl;
  return 0;
}