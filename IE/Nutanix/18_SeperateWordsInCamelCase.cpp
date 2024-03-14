// Seperate words in Camel Case
// tc : O(N)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string input = "HelloWorldA";
  string res = "";
  for (int i = 0; i < input.size(); ) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      res.push_back(input[i]);
      i++;
      while (input[i] >= 'a' && input[i] <= 'z') {
        res.push_back(input[i]);
        i++;
      }
      if (i >= input.size()) {
        break;
      } else {
        res.push_back('_');
        continue;
      }
    }
  }

  for (auto ch : res) {
    cout << ch;
  }
  cout << endl;
}
