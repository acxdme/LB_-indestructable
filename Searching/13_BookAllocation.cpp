// Only ans part of the check Conditon remaining

    bool checkCondition(int A[],int &n  , int &m ,int mid){
        int count = 0;
        int sum = 0;
        for(int i = 0 ; i < n;i++){
            sum += A[i];
            if(sum == mid){
                count++;
                sum = 0;
            }
            else if (sum > mid){
                count ++;
                sum = A[i];
            }
        }
        if(sum > 0){
            count ++;
        }
        
        return count == m;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        
        int sum = 0 ;
        for(int i= 0 ; i < N ;i ++){
            sum += A[i];
        }
        int start = A[0];
        int end = sum;
        int mid = start + (end-start)/2;
        int result = INT_MAX;

        while(start <=end){
            if(checkCondition(A,N,M,mid,res)){
                cout<<"mid "<<mid <<endl;
                res = min(res,mid);
                end = mid -1;
            }
            else{
                start = mid +1;
            }
            
            mid = start + (end-start)/2;
        }
        
        if(res == INT_MAX){
            return -1;
        }
        
        return res;
    }

//-------------------------------------------------------------------------------------------------------------------------
// after watching video of the code , got the explaination

    bool checkCondition(int A[],int &n  , int &m ,int mid){
        int count = 1;
        int sum = 0;
        

        for(int i = 0 ; i < n ; i++){
            if(A[i] > mid) return false;
            if(sum + A[i] > mid){
                count++;
                sum = A[i];
                
                if(count > m){
                    return false;
                }
            }
            else{
                sum += A[i];
            }
        }
        
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if( M > N) return -1;
        
        int sum = 0 ;
        // sort(A,A+N);
        for(int i= 0 ; i < N ;i ++){
            sum += A[i];
        }
        int start = A[0];
        int end = sum;
        int ans = -1;
        int mid = start + (end-start)/2;
        
        while(start <= end){
            
            if(checkCondition(A,N,M,mid)){
                ans =mid;
                end = mid -1;
            }
            else{
                start = mid +1;
            }
            
            mid = start + (end-start)/2;
        }
        
        
        return ans ;
    }
