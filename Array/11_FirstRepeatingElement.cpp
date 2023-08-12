// Time-complexity : O(N)
// Space-complexity : O(N)

/**
Given an array arr[] of size n, find the first repeating element.
The element should occur more than once and the index of its first occurrence should be the smallest.
*/

class Solution {
  public:
    
    int firstRepeated(int arr[], int n) {
        // hashmap approach , TC: O(N) , SC: O(N)
        unordered_map<int,int> mp; // <num,freq>
        int ans = INT_MAX;
        for(int i =  0 ; i<n;i++){
            if(mp.find(arr[i]) != mp.end()){
                ans = min(ans,mp[arr[i]]);
            }
            mp[arr[i]] = i +1 ;
        }
        
        if(ans == INT_MAX) ans = -1;
        
        return ans;
    }
};
