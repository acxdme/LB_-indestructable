// lc - 215
// tc :  O(n log k)
// sc  : O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int> > pq; // min heap

        int i = 0;
        while( i < k){
            pq.push(nums[i]);
            i++;
        }

        while(i < nums.size()){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }



        return pq.top();
    }
};
