// T.C : O(N)
// S.C : O(1)
// gfg : (similar question) https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751

#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {1,2,0,4,3,0,5,0};
  int n = v.size();
  cout<<n << endl;
  // end index as reference partition
  int j = n-1;
  
  for(int i = j ; i>=0 ;i--){
    if(v[i] != 0 ){
      swap(v[i],v[j]);
      j--;
    }
  }

  // print the array
  for(auto i : v){
    cout<< i << " ";
  }cout<<endl;
  return 0;
}
