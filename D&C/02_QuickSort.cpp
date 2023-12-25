// check variations
// algo : partion , qs(left) ,qs(right)
// tc : O(nlogn)
// sc : O(n) , considering recursion stack

#include <iostream>
using namespace std;

int partition(int arr[] , int s , int e){
  int pivotIndex = s;
  int count = 0;
  int i = s+1;
  while(i <= e){
    if(arr[i] <=arr[pivotIndex]){
      count++;
    }
    i++;
  }
  //place pivot at right index
  pivotIndex = count +s;
  swap(arr[s],arr[pivotIndex]);
   i = s;
   int j = e;
   int pivot = arr[pivotIndex];
   while(i < pivotIndex && j > pivotIndex){
      while(arr[i] <= pivot){
        i++;
      }
      while(arr[j] > pivot){
        j--;
      }
      if(i < pivotIndex && j > pivotIndex){
        swap(arr[i],arr[j]);
      }
   }

   return pivotIndex;

}

void quickSort(int arr[] ,int s , int e){
  if(s >= e){
    return ;
  }

  // partition
  int p = partition(arr,s,e);

  // qs left half
  quickSort(arr,s,p-1);
  // qs right half
  quickSort(arr,p+1,e);
}

int main() {
  int arr[] = {4,3,5,9,2,1,8,8,8,8,8,8,1,78,34,56,57,57,56,9};
  int n = 20;
  quickSort(arr,0,n-1);
  for(int i =0 ;i < n ;i++){
    cout<<arr[i] <<" ";
  }cout<<endl;
  return 0;
}
