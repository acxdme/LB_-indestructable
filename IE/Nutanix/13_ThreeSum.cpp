// tc : O(N^2)
// sc : O(1)
// lc -15
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i =0 ; i < size-2 ;i++ ){
            int j = i + 1;
            int k = size -1;
            int first = nums[i];
            while(j < k){
                int second = nums[j];
                int third = nums[k];
                if(first + second + third == 0){
                    st.insert({first,second,third});
                    j++;
                    k--;
                }
                else if( first + second + third > 0 ){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        
        vector<vector<int>> result;
        for(auto item : st){
            result.push_back(item);
        }

        return result;
    }
};
