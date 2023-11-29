//TC : O(N^2)
//SC : O(N)

#include <iostream>
using namespace std;

void printAllSubArrays_util(int arr[] ,int &n , int i , int j){
  if( j >= n) return;

  for(int k = i ; k <=j ;k++){
    cout<<arr[k]<<" ";
  }cout<<endl;
  
  printAllSubArrays_util(arr,n,i,j+1);
}

void printAllSubArrays(int arr[] ,int &n  ){
  for(int start = 0 ; start < n ;start++){
    int end = start;
    printAllSubArrays_util(arr,n,start,end);
  }
}


int main() {
  
  int  arr[] = {1,2,3,4,5};
  int n = 5;
  printAllSubArrays(arr,n);
  return 0;
}
