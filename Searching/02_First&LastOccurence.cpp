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
