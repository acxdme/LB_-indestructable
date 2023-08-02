//lc-1004
// Maximum consecutive 1s

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if( n == 0 ) return 0;

        int startIndex = 0;
        int count = k;
        int mxLen = INT_MIN;

        for(int i = 0 ;i< n ;i++){
            if(nums[i] == 0){
                count--;
                if(count < 0){
                    while(count < 0){
                        if(nums[startIndex] == 0){
                            count++;
                        }
                        startIndex++;
                    }
                }
            }
            mxLen = max(mxLen,i-startIndex+1);
        }

        return mxLen;
    }
};
