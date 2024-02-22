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
