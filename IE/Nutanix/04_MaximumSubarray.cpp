// lc - 53
// tc - O(N)
// sc - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int sum = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int currVal = nums[i];
            sum = max(sum+currVal , currVal);
            maxi = max(maxi,sum);
        }

        return maxi;
        
    }
};

//----------------------------------------------------------------------------------------
// Variation question : Save Your Life
// GFG
 string maxSum(string w,char x[], int b[],int n){
            // map for redefined values
            unordered_map<char,int> mp;
            for(int i =0 ; i< n;i++){
                mp[x[i]] = b[i];
            }
            
            int localSum = 0;
            int globalSum = INT_MIN;
            int start = 0 , end = 0 , ptr = 0;
            for(int i =0 ; i< w.size() ; i++){
                int currentVal = (int) w[i];
                if(mp.find(w[i]) != mp.end()){
                    currentVal = mp[w[i]];
                }
                
                localSum += currentVal;
                if(localSum > globalSum){
                    globalSum = localSum;
                    start = ptr;
                    end = i;
                    
                }
                if(localSum < 0 ){
                    localSum = 0;
                    ptr = i+1;
                }
            }
            
            return w.substr(start,end-start +1);
      }
