 void quickSort(int arr[], int low, int high)
    {
        if(low >= high) return;
        
        int p = partition(arr,low,high);
        
        quickSort(arr,low,p-1);
        
        quickSort(arr,p+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivotIndex = low;
       int count = 0 ;
    //   int e = sizeof(arr) / sizeof(arr[0]);
       for(int j = pivotIndex+1 ; j <= high;j++){
           if(arr[j] <= arr[pivotIndex]) count++;
       }
       
       
       
       int rightIndex = pivotIndex+ count;
       swap(arr[pivotIndex],arr[rightIndex]);
       
       int i  = low ;
       int j  = high;
       
       while( i < rightIndex && j > rightIndex){
           while(arr[i] < arr[rightIndex]) i++;
           while(arr[j] > arr[rightIndex]) j--;
           
           if( i < rightIndex && j > rightIndex)
             swap(arr[i],arr[j]);
       }
       
       return rightIndex;
    }
