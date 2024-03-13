// tc : O(log N)
// sc : O(1)

class Solution {
public:
    int findTarget(vector<int>& nums , int target){

        int start = 0;
        int end = nums.size() -1;

        int mid = start + (end - start)/2;

        while( start <= end){
            if(nums[mid] == target ){
                return mid;
            }
            if( nums[mid] >= nums[start]){ // yaha pe galti karoge , test cases basic wale bhi chalo
                if(target >= nums[start] && target < nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid +1;
                }
            }
            else if(nums[end] >= nums[mid]){ // yaha pe galti
                if(target > nums[mid] && target <= nums[end]){
                    start = mid +1;
                }
                else{
                    end = mid -1;
                }
            }

            //update mid 
            mid = start + (end - start)/2;
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
     
       if(nums.size() == 0) return 0;
       int result = findTarget(nums,target);
       

        return result;
        
    }
};
