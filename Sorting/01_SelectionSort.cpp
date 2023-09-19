// selection sort
// gfg
// tc : O(N^2) , sc : O(1)

    int select(int arr[], int i)
    {
        int max_index = i;
        for(int k = i ;k >=0 ;k--){
            if(arr[max_index] < arr[k]){
                max_index = k;
            }
        }
        
        return max_index;
    }
     
    void selectionSort(int arr[], int n)
    {
       for(int i = n-1 ; i > 0 ; i--){
           int max_index = select(arr, i);
           swap(arr[i],arr[max_index]);
       }
    }
