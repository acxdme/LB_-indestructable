// range logic issue in checkArray inorder function

#include <iostream>
using namespace std;

bool isArrayInorder(int arr[], int n) {
    if (n == 0)
        return true;
    for (int i = 0; i < n-1; i++) // correction in for loop :  [0 ,n-1)
        if (arr[i] > arr[i+1])
            return false;
    return true;
}

int main() {
  int arr[] = {1,2,3,8,9};
  bool ans = isArrayInorder(arr,5);
  if(ans){
     cout<<"Array inorder hai"<<endl;
  }
  else{
     cout<< "Array is not inorder"<<endl;
  }
  return 0;
}
