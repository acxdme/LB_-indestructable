// gfg -https://www.geeksforgeeks.org/problems/heap-sort/1
// tc : O(N logN)
// sc : log(N)

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largestIndex = i;
        int leftIndex = 2*i + 1;
        int rightIndex = 2*i + 2;
        
        if((leftIndex < n) && arr[leftIndex] > arr[largestIndex] ){
            largestIndex = leftIndex;
        }
        if((rightIndex < n) && arr[rightIndex] > arr[largestIndex]){
            largestIndex = rightIndex;
        }
        
        if(largestIndex != i){
            swap(arr[largestIndex] ,arr[i]);
            heapify(arr,n,largestIndex);
        }
      
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
       int k = (n-1)/2;
       for(int i = k ; i >= 0 ; i--){
           heapify(arr,n,i);
       }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // build the heap
        buildHeap(arr,n);
        
        // swap(first,last) and heapify
       int first = 0;
       int last = n-1;
       while(last > first){
            swap(arr[first],arr[last]);
            heapify(arr,last-first,first);
            last--;
        }
    }
};
