// Dutch national flag problem.
// lc-75
// time-complexity : O(N)
// space-complexity : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int i = 0 ;
        int start = 0;
        int end = n-1;

        while(i <= end){
            if(nums[i] == 0){
                swap(nums[i],nums[start]);
                i++;
                start++;
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[end]);
                end--;
            }else{
                //1
                i++;
            }
        }
        
    }
};
