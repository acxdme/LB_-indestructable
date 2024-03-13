// tc -  O(N^2)
// sc - O(1)
// lc - 2006

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) { // yaha pe sort karke two pointers wali galti mat karna
        int count = 0;
        for(int i =0 ; i < nums.size() ; i ++){
            for(int j = i + 1  ; j < nums.size() ; j++){
                if(abs(nums[i] - nums[j]) == k){
                    count++;
                }
            }
        }

        return count;
    }
};
