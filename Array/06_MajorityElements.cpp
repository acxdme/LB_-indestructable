// lc-169
// TC - O(N) , SC - O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = -1;
        for(int i =0  ; i < n ;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/2){
                ans = nums[i];
            }
        }

        return ans;
    }
};

// approach , sort the array , give the  n/2 th element in the array. TC : O(N*logN) , SC : O(1).
