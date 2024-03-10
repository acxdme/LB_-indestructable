// Method-1
// a)Find the pivot element (max wala) {Pivot element is the element at which the monotonic order breaks}
// b) apply binary search on the subarray for which the target lies in the range of subarray.


//method-2
//comparing with ends solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0 ;
        int end = n -1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start <= end){
            if(target == nums[mid]){
                ans = mid;
                break;
            }
            if(nums[mid] >= nums[start]){
                if( target >= nums[start] && target < nums[mid])
                  end = mid -1;
                else{
                    start = mid +1;
                }
            }
            else if(nums[end] >= nums[mid]){
                if( target > nums[mid] && target <= nums[end]){
                    start = mid + 1;
                }
                else{
                    end = mid -1;
                }
            }
            mid = start + (end-start)/2;
        }

        return ans;
        
    }
};
