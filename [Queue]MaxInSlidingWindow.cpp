class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 0 ) return ans;

        int mx = INT_MIN;
        deque<int> q;

        //process for first window of size k
        for(int i = 0 ; i < k ; i++){

            while(!q.empty() && nums[q.back()] <= nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            
        }

        // result for 1st window
        ans.push_back(nums[q.front()]);

        // process for remaining windows
        for(int i = k ; i< nums.size() ; i++){

            while(!q.empty() && i - q.front() >= k){
                q.pop_front();
            }

            while(!q.empty() && nums[q.back()] <= nums[i]){
                q.pop_back();
            }

            q.push_back(i);

            ans.push_back(nums[q.front()]);
        }

        return ans;
        
    }
};
