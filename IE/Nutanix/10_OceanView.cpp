// Based on the pattern of next-greater
// tc : O(N)
// sc : O(N)
// lc-1762 , ocean view

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
   vector<int> houses = {5,4,3,2,1};
   stack<int> st;
   int size = houses.size();
   st.push(-1); // -1 as reference value
   st.push(size -1);  // last house has ocean view
   vector<int> result;
   result.push_back(size -1);
   for(int i = houses.size() - 2  ; i >= 0 ; i--){
      int currentHeight = houses[i];
      while(!st.empty() && houses[st.top()] <= currentHeight){
         st.pop();
      }
      if(st.empty()){
        result.push_back(i);
      }
      st.push(i);
   }


  for(int i = result.size() -1 ; i >=0 ; i--){
     cout<< result[i] <<" ";
  }cout<<endl;
}
