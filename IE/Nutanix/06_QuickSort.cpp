// tc : O(N*logN) average case
// sc : O(log N)

void quickSort(int arr[], int low, int high)
    {
          // base-case
          if(low >= high){ // yaha pe galti , never miss the base-case
                return ;
           }
        int partitionIndex = partition(arr,low,high);
        
        // qs left 
        quickSort(arr,low,partitionIndex - 1);
        
        // qs right
        quickSort(arr,partitionIndex + 1 , high);
        
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int pivotIndex = low;

       int countGreater = 0;
       for(int i = low + 1; i <= high ; i++ ){
           if(arr[i] <= arr[pivotIndex] ){ // yaha pe galti , chote wale chaiye count
               countGreater++;
           }
       }
       
       //swap
       pivotIndex = countGreater + low; // yaha pe galti karoge , har baar alag tukde milenge
       swap(arr[low],arr[pivotIndex]);
       
       
       int i = low ;
       int j = high;
       
       while( i < pivotIndex && j > pivotIndex ){
           while(arr[i] <= arr[pivotIndex]){
               i++;
           }
           while(arr[j] > arr[pivotIndex]){
               j--;
           }
           
           if( i < pivotIndex && j > pivotIndex)
            swap(arr[i],arr[j]);
       }
       
       return pivotIndex;
    }
