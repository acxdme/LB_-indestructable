// Time complexity : O(N)
// space complexity : O(1)
// lc-287

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i =0 ; i< n ; i++){
            if(nums[abs(nums[i]) - 1] < 0)
            {
                return abs(nums[i]);
            }
            nums[abs(nums[i]) - 1] *= -1;
        }
        
        return -1;
    }
};

// ---------------------------------------------------------
// Another approach  
// TC : O(N) , SC : O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();
        for(int i =0 ; i < n ; i++ ){ // make all negative 
            nums[i] *= -1;
        }
        for(int i =0 ; i < n ; i++){
            if(nums[abs(nums[i])] > 0 ) return abs(nums[i]); // found already visited.
            else{
                nums[abs(nums[i])] *= -1; // mark visited index as positive.
            }
        }
        // todo : remove pending negative sign

        return -1;
        
    }
};
