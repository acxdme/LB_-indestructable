// tc : O(N^2)
// sc : O(1)
//gfg
    void insert(int arr[], int i)
    {
        int val = arr[i]; // fetching
        while(i > 0){
            if(arr[i-1] > val ){
                arr[i] = arr[i-1]; // shifting
                i--;
            }
            else{
                break;
            }
        }
        arr[i] = val;
        
    }
     public:
    void insertionSort(int arr[], int n)
    {
       for(int round = 1 ; round < n ; round ++){
           insert(arr,round);
       }
    }
