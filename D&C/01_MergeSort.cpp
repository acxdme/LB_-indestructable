// tc : O(Nlogn)
// sc : O(N)

#include <iostream>
using namespace std;

void merge(int arr[], int start ,int mid ,int end){

  int l1 = mid - start +1;
  int l2 = end - mid;

  int* leftPart = new int[l1];
  int* rightPart = new int[l2];

  int leftIndex = 0;
  int rightIndex = 0;
  int originalIndex = start;

  while(leftIndex < l1){
    leftPart[leftIndex++] = arr[originalIndex++];
  }
  // originalIndex = mid+1;
  while(rightIndex < l2){
    rightPart[rightIndex++] = arr[originalIndex++];
  }

   leftIndex = 0;
  rightIndex = 0;
  originalIndex = start;

  while(leftIndex < l1 && rightIndex < l2){
     if(leftPart[leftIndex] < rightPart[rightIndex]){
       arr[originalIndex++] = leftPart[leftIndex++];
     }
     else{
        arr[originalIndex++] =rightPart[rightIndex++];
     }
  }

  if(leftIndex < l1){
    while(leftIndex < l1){
      arr[originalIndex++] = leftPart[leftIndex++]; 
    }
  }

  if(rightIndex <l2){
    while(rightIndex < l2){
      arr[originalIndex++] = rightPart[rightIndex++];
    }
  }

}

void mergeSort(int arr[], int start ,int end){
   if(start >= end) return;

   int mid = start + (end-start)/2;

   //left part
   mergeSort(arr,start,mid);

   //right part
   mergeSort(arr,mid+1,end);

   //merge the two parts
   merge(arr,start,mid,end);
}

int main() {
  int arr[] = {8,3,6,7,1,5,2,2,2,2,1};
  int n = 11;
  mergeSort(arr,0,n-1);

  for(int i =0 ; i< n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;


  return 0;
}

// inplace merge-sort
