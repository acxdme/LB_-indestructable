// incorrect logic 
// need prev, curr pointers to track positions.
class Solution {
public:
    int findLengthRecursion(vector<int>& nums,int index, int size){
        // base-case
        if(index > size){ // out-of-bound
            return 0;
        }
        
        int maxi = INT_MIN;
        //take
        int include = 0;
        if(index == 1 || nums[index] > nums[index -1] ) // increasing
        {
            include = 1 + findLengthRecursion(nums,index + 1 , size);
        }
        
        // not-take
        int exclude = 0 + findLengthRecursion(nums,index+1 ,size);

        maxi = max(include,exclude);

        return maxi;
    }
    int lengthOfLIS(vector<int>& nums) {

        //Recursion
        int n = nums.size();
        if(n <= 1) return n;
        int index = 1;
        nums.insert(nums.begin(),-1);
        int res = findLengthRecursion(nums,index,n);

        return  res;
        
    }
};
// --------------------------------------------------------------------------------------------
