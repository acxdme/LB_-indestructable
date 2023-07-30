//leetcode-209

/** algo :  a)start with window of size 1 from left
             b)expand upto target
             c)minimize for target
**/            

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int start = 0;
        int end = 0;
        int size = nums.size();
        int minLength = INT_MAX;
        int sum  = 0;

        while( end < size){
            sum += nums[end];

            if(sum >= target){

                while(start <= end && sum >= target){
                    sum -= nums[start];
                    start++;
                }

                minLength = min(minLength , end - start +2);
            }
            end++;
        }

        if(minLength == INT_MAX){
            return 0;
        }

        return minLength;
    }
};

-----------------------------------------------------------------

  // some code refactoring for better readability

  class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int start = 0;
        int end = 0;
        int size = nums.size();
        int minLength = INT_MAX;
        int sum  = 0;

        while( end < size){
            sum += nums[end];

            if(sum >= target){

                while( sum >= target){
                    minLength = min(minLength , end - start +1);
                    sum -= nums[start];
                    start++;
                }

            }
            end++;
        }

        if(minLength == INT_MAX){
            return 0;
        }

        return minLength;
    }
};
