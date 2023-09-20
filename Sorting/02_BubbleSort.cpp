// tc : O(N^2)
// sc : O(1)
// gfg 


    void bubbleSort(int arr[], int n)
    {   
        int isSorted = true;
        for(int round = 1; round < n; round++){
            
            for(int i =0 ; i < n- round ;i++){
                if(arr[i] > arr[i+1]){
                    isSorted = false;
                    swap(arr[i],arr[i+1]);
                }
            }
            
            if(isSorted){
                break;
            }
        }
    }
