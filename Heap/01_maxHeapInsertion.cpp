
#include <iostream>
#include <vector>
using namespace std;

void insertInHeap(vector<int> &heap , int data){
  //put data into last of heap
  heap.push_back(data);

  int n = heap.size();
  int i = n-1;
  while((i/2 > 0) && (heap[i/2] < heap[i])){
    swap(heap[i/2],heap[i]);
    i = i/2;
  }

  //arrange the data into it's correct position

}

int main() {
  // insertion in heap
  vector<int> heap = {-1,60,30,40};

  for(int i =1 ;i < heap.size() ; i++){
    cout<<heap[i]<<" ";
  }cout<<endl;

  
  insertInHeap(heap,70);

    for(int i =1 ;i < heap.size() ; i++){
    cout<<heap[i]<<" ";
  }cout<<endl;
  return 0;
}
