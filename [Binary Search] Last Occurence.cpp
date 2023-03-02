/*
Time complexity : O(log n)
*/

#include<iostream>
#include<vector>

using namespace std;

int findLastOccurence(vector<int>&v , int n , int target)
{
  int start =0 ;
  int end = n-1;
  int mid = start + (end-start)/2;
  int index = -1;
   while(start<=end){
      if(v[mid] == target){
        index = mid;
        start = mid +1;
      }
     else if (target < v[mid]){
       end = mid -1 ;
     }
     else{
       start = mid +1;
     }
     mid = start + (end-start)/2;
   }

  return index;
}

int main(){
  vector<int> v = {1,2,3,3,3,3,4,4,4,4,4,4,4,4,5};
  int target = 1;

  int lIndex = findLastOccurence(v,v.size(),target);

  if(lIndex >= 0 ){
  cout<<"target "<<target<<" last found at index "<<lIndex<<endl;
  }else{
    cout<<"target not found"<<endl;
  }

  
  return 0;
}
