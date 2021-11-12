#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::string;
using std::unique_ptr;
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
  ifstream namesStream("names.txt");
  if(!namesStream) { 
    cerr << "Error while opening file handle" << endl;
    return -1;
  }
  namesStream.seekg(0, ios::end);
  int fileSize = namesStream.tellg();
  namesStream.seekg(0, ios::beg);
  unique_ptr<char> namesData(new char[fileSize]);
  namesStream.read(namesData.get(), fileSize);
  cout.write(namesData.get(), fileSize);
  namesStream.close();
  return 0;
}
