
```
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //max heap
        priority_queue<int> pq;
        
        int i = l;
        
        while( i < k){
            pq.push(arr[i]);
            i++;
        }
        
        while(i <= r){
            if(arr[i] < pq.top() ){
                pq.pop();
                pq.push(arr[i]);
            }
            i++;
        }
        
        return pq.top();
    }
};
```

