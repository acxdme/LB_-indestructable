/*
first occurence in a sorted array.
Time complexity : O(log n) [base is 2]
*/

// lower_bound(arr,arr+n,target)


#include<iostream>
#include<vector>

using namespace std;

int findFirstOccurence(vector<int> &v ,int n ,int &target){

  int index = -1;
  int start = 0;
  int end = v.size()-1;
  int mid = start + (end-start)/2;
  while(start <= end){
    if(v[mid] == target ){
      index = mid;
      end = mid-1;
    }
    else if (v[mid] < target){
      start = mid +1;
    }
    else{
      end = mid-1;
    }
    mid = start + (end-start)/2;
  }
  return  index;
}


int main(){
  vector<int> v = {1,2,3,3,3,3,4,5};
  int target = 3;
  int index = findFirstOccurence(v,v.size(),target);
  if(index >= 0 ){
  cout<<"target "<<target<<" first found at index "<<index<<endl;
  }else{
    cout<<"target not found"<<endl;
  }
  return 0;
}
