 void merge(int arr[], int l, int mid, int r)
    {
         // length of new arrays
        //  int mid = (l+r)/2;
         int len1 = mid-l+1;
         int len2 = r-mid;
         
         // dynamic intialization of the two arrays
         int* arr1 = new int[len1];
         int* arr2 = new int[len2];
         
         //copy karo arr1 and arr2 mei original array sei 
         int k =l;
         for( int i = 0 ;i < len1 ; i++){
             arr1[i] = arr[k++];
         }
         
         k = mid+1;
         for( int j =0 ;j<len2; j++){
             arr2[j] = arr[k++];
         }
         
         //compare karke merge karo ab.
         int i =0,j =0; 
          k = l;
         while(i < len1 && j < len2){
             if(arr1[i] < arr2[j]){
                 arr[k++] = arr1[i++];
             }
             else{
                 arr[k++]=arr2[j++];
             }
         }
         
         while(i < len1){
             arr[k++] = arr1[i++];
         }
         while(j < len2){
             arr[k++] = arr2[j++];
         }

         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //base-case
        if(l >= r) return;
        
        int mid = l + (r-l)/2;
        
        mergeSort(arr,l,mid);
        
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
