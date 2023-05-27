/*
  Time complexity : O(n + k*logn)
  Space complexity : O(n)
*/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        // insert piles into max heap
         for(int i =0 ;i< piles.size();i++){
             pq.push(piles[i]);
         }

        // remove top from heap , apply Kth operation and insert back into max heap
        while(k--){
            int tp = pq.top();
            pq.pop();
            tp = tp - floor(tp/2);

            pq.push(tp);
        }

        // add the updated values of piles and return answer.
        int ans = 0;
        while(!pq.empty()){
            int tp = pq.top();
            pq.pop();
            ans += tp;
        }

        return ans;

    }
};
