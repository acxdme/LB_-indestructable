// lc -2279
// tc : (N* log N)
// sc : O(N)

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,
                    int additionalRocks) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = rocks.size();
        for (int i = 0; i < n; i++) {
            int diff = capacity[i] - rocks[i];
            if (diff >= 0) {
                pq.push(diff);
            }
        }

        int counter = 0;

        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            additionalRocks -= top;

            if (additionalRocks >= 0) {
                counter++;
            } else {
                break;
            }
        }

        return counter;
    }
};
