// Jump-Game-2
// Tried with recursive approach.
class Solution {
public:

    void findMinJumps(int index , vector<int> &nums, int jumps , int &mnJumps){
        //base-case
        if(index >= nums.size() - 1){
            mnJumps = min(mnJumps,jumps);
            return;
        }

        // recursion
        int i = index;
        while(( i < (nums.size() - 1)) &&  i < index + nums[index] ){
            i++;
            findMinJumps(i,nums,jumps + 1 , mnJumps);
        }

    }
    int jump(vector<int>& nums) {
        
        int index = 0;
        int jumps = 0; 
        int mnJumps = INT_MAX;
        findMinJumps(index,nums,jumps,mnJumps);

        return mnJumps;
    }
};



//------------------------------------------------------
// correct approach to write the code : 

    long long  int findMinJumpsMemo(int index , vector<int> &nums , int n, vector<int> &dp){

        // base-case ( already reached)
        if( index >= n-1){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        

        long long int mini = INT_MAX;
        // yaha pe galti karunga mei.
        
        for(int jump = 1 ; jump <= nums[index] ;jump++){
            
            long long int res = 1 + findMinJumpsMemo(index + jump,nums,n,dp);

            mini = min(res,mini);
        }
        dp[index] = mini;

        return dp[index];
    }
