// Count the Number of Substrings With Dominant Ones
// Brute force : O(N^3) , Optimized : O(N^2)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count0 = 0;
        int count1 = 0;
        int dominantString = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (s[j] == '0')
                    count0++;
                else
                    count1++;

                if (count1 >= count0 * count0) {
                    dominantString++;
                    // cout<<"{ "<<i<<","<<j<<" }"<<endl;
                }
            }
            count0 = 0;
            count1 = 0;
        }

        return dominantString;
    }
};
