// tc -O(N log m) 
// sc - O(m), size of strin m [1,200]
// lc - 14

#include <iostream>
#include <vector>

using namespace std;

bool isValidLCP(vector<string> &strs, int mid, string &result) {
  string prefix = "";
  int n = strs.size();
  for (int i = 0; i < n; i++) {
    if (strs[i].size() < mid) {
      return false;
    } else {
      if (i == 0)
        prefix = strs[i].substr(0, mid);
      else {
        if (strs[i].substr(0, mid) != prefix) {
          return false;
        }
      }
    }
  }
  result = strs[0].substr(0, mid);
  return true;
}

string findLCP(vector<string> &strs) {
  int start = 1;
  int end = 200;
  int mid = start + (end - start) / 2;
  string res = "";
  while (start <= end) {
    if (isValidLCP(strs, mid, res)) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }

  return res;
}
int main() {
  vector<string> strs = {"flower", "flow", "flight"};

  string ans = findLCP(strs);

  for (auto ch : ans) {
    cout << ch;
  }
  cout << endl;

  return 0;
}
