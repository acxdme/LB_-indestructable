// lc - 3075
// tc - N * log N
// sc - O(N)

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> maxHeap; // maxHeap
        int n = happiness.size();

        for (int i = 0; i < n; i++) {
            maxHeap.push(happiness[i]);
        }

        int dec = 0;
        long long int result = 0;
        while (k--) {
            int top = maxHeap.top();
            maxHeap.pop();
            if (top - dec > 0) {
                result += top - dec;
            } else {
                break;
            }

            dec++;
        }

        return result;
    }
};
