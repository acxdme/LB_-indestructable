// gfg - https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1
// tc : O(N)
// sc : O(N)

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q1){
        
        int half = q1.size() / 2;
        vector<int> res;
        
        // create q2 for 1st part
        queue<int>q2;
        
        int i = 0;
        //insert 1st half of q1 into q2
        while(i < half){
            int front1 = q1.front();
            q1.pop();
            
            q2.push(front1);
            
            i++;
        }
        
        //interleave until the q's are empty
        while((!q1.empty()) && (!q2.empty())){
            
            int front2 = q2.front();
            q2.pop();
            
            int front1 = q1.front();
            q1.pop();
            
            res.push_back(front2);
            res.push_back(front1);
            
        }
        
        return res;
        
    }
};
