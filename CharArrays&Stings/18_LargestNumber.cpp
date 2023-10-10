// tc : O(N^2)
// sc : O(N)
// lc-179

class Solution {
public:

    bool isLarge(string& large , string& curr){
        if(curr + large > large + curr){
            return true;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {

        string res = "";
        vector<string> strNums;
        int n = nums.size();
        for(int i = 0 ;i < n ;i++ ){
            string strNum = to_string(nums[i]);
            strNums.push_back(strNum);
        }

        for(int i =0 ; i < n - 1 ;i++){
            string largest = strNums[i];
            int swapIndex = i;
            for (int j = i + 1 ; j < n ; j++){
                string curr = strNums[j];
                if(isLarge(largest,curr) ){
                    largest = curr;
                    swapIndex = j;
                }
            }
            swap(strNums[i] ,strNums[swapIndex]);

        }
        for(auto str : strNums){
            res += str;
        }
        
        int allZeros = 1;
        for(auto ch : res){
            if(ch != '0')
               { 
                   allZeros = false;
                   false;
               }
        }
        if( allZeros) return "0";
        return res;
    }
};
