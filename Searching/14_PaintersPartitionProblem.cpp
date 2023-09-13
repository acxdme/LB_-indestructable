// time complexity : O(NlogN)
// space complexity : O(1)
// gfg : painters partition: II

    bool checkCondition(int arr[] ,int n ,int k ,long long int sol){
        int count = 1;
        long long int presum = 0;
        
        for(int i = 0 ; i< n; i++){
            if(arr[i]  > sol ) return false;
            if( presum + arr[i]  > sol){
                count++;
                presum = arr[i];
            }
            else{
                presum += arr[i];
            }
            
            if(count  > k) return false;
        
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long int sum = 0;
        int mx = -1;
        
        for(int i = 0 ;i < n ;i++){
            sum += arr[i];
            mx = max(mx,arr[i]);
        }
        
        long long int start = mx ;
        long long int end = sum;
        long long int mid = start + (end -start) /2;
        long long int ans = -1;
        
        while(start <= end){
            if( checkCondition(arr,n ,k , mid) ){
                ans = mid;
                end = mid -1;
            }else{
                start = mid + 1;
            }
            
            mid = start + (end -start) /2;
        }
        
        return ans;
    }
