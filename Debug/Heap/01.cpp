// heapSort

#include <iostream>
using namespace std;

void heapify(int arr[], int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) { // fix : largest != currentIndex(i)
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
    for (int i = (N - 1) / 2 ; i >= 0; i--) // fix in for loop intialization
        heapify(arr, N, i);
    for (int i = N - 1 ; i > 0; i--) { // fix in for loop range
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
  int arr[] = {4,8,2};
  heapSort(arr,3);
  for(auto it : arr){
    cout<<it<<" ";
  }cout<<endl;
  return 0;
}

