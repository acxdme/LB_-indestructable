// next greater element to the left

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreaterElementLeft(vector<int> input, int n){
		vector<int> left(n,-1);
		stack<int> s;
		for(int i=0; i<n; i++){
				while(!s.empty() && input[s.top()] <= input[i]){
						s.pop();
				}
        if(!s.empty()){ // fix : stack empty condition added
				 left[i] = input[s.top()]; // store value in array not the indexes.
        }
				s.push(i);
		}

    for(auto it : left){
      cout<<it <<" ";
    }cout<<endl;
}


int main() {
  vector<int> input = {8,2,7,9,8,9,8,6,0,1};

  int n = 10;
  nextGreaterElementLeft(input,n);

  return 0;
}
