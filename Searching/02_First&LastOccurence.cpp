// gfg
// TC - O(log N)

// wrong implementation , this will not find the first index of an absent element
// ex : 1 1 3 4 5 6 8 9 , target =2 , would give wrong result with stl functions .
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long int firstOcc = -1;
        long int lastOcc = -1;
        
        firstOcc = lower_bound(v.begin(),v.end(),x) - v.begin();
        lastOcc = upper_bound(v.begin(),v.end(),x) - v.begin() -1;
        
        if(firstOcc == v.size()) return {-1,-1};
        
        return {firstOcc,lastOcc};
    }

//--------------------------------------------
// Using self-created functions

   long int findFirst(vector<long long>& v,int n , long long target){
        
        int start = 0;
        int end = n-1;
        int mid = start + (end - start)/2;
        int firstIndex = -1;
        
        while(start <= end){
            if(v[mid] == target)
            {
              firstIndex = mid;
              end = mid -1;
              
            }
            else if( v[mid] > target){
              end = mid -1;
            }
            else{
               // v[mid] < target 
               start = mid +1;
            }
            
            mid = start + (end -start)/2;
        }
        
        return firstIndex;
        
    }
    
    long int findLast(vector<long long>& v,int n , long long target){
        
        int start = 0;
        int end = n-1;
        int mid = start + (end - start)/2;
        int lastIndex = -1;
        
        while(start <= end){
            if(v[mid] == target)
            {
              lastIndex = mid;
              start = mid +1;
              
            }
            else if( v[mid] > target){
              end = mid -1;
            }
            else{
               // v[mid] < target 
               start = mid +1;
            }
            
            mid = start + (end -start)/2;
        }
        
        return lastIndex;
        
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        long int firstOcc = -1;
        long int lastOcc = -1;
        
        int n = v.size();
        firstOcc = findFirst(v,n,x);
        lastOcc =  findLast(v,n,x);
     
        
        return {firstOcc,lastOcc};
    }
