// next greater to the right , revist the official answer.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreaterElementRight(vector<int>& input, int n){
		vector<int> right(n,-1);
		stack<int> s;
		for(int i=n-1; i >= 0; i--){
				if(s.empty()){
						s.push(i);
            continue;
				}
				while(!s.empty() && input[s.top()] <= input[i]){
						s.pop();
				}
        if(!s.empty()){
				  right[i] = input[s.top()];
        }
        s.push(i);
		}

    for(auto it : right){
      cout<<it <<" ";
    }cout<<endl;
}

void nextGreaterElementRight2(vector<int> input, int n){
		vector<int> right(n,-1);
		stack<int> s;
		for(int i=0; i<n; i++){
				if(s.empty()){
						s.push(i);
						continue;
				}
				while(!s.empty() && input[s.top()] < input[i]){
						right[s.top()] = input[i];
						s.pop();
				}
				s.push(i);
		}

        for(auto it : right){
      cout<<it <<" ";
    }cout<<endl;
}



int main() {
  vector<int> input = {8,2,7,9,8,9,8,6,0,1};

  int n = 10;
  nextGreaterElementRight(input,n);
  nextGreaterElementRight2(input,n);

  return 0;
}
