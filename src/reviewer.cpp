#include <iostream>
#include <chrono>
#include <memory>
#include <string>
#include <random>
#include <vector>
#include <fstream>

using std::cerr;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::ifstream;
using std::ios;
using std::string;
using std::uniform_int_distribution;
using std::unique_ptr;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

vector<string> grabWords(string input) {
    vector<string> result;
    string temp;
    for (int i = 0; i < input.length(); i ++) {
      char c = input[i];
      if (c == ' ' || c == '\t' || c == '\n') {
          if (temp.length() > 0) {
            result.push_back(temp);
            temp = string();
          }
      }else {
            temp += c;
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
  namesStream.close();
  vector<string> names = grabWords(string(namesData.get()));
  default_random_engine generator;
  generator.seed(
      duration_cast<nanoseconds>(
          high_resolution_clock::now().time_since_epoch())
          .count());
  uniform_int_distribution<int> distribution(0,names.size() - 1);
  string firstName = names[distribution(generator)];
  string lastName = names[distribution(generator)];
  cout << firstName << " " << lastName << endl;
  return 0;
}
