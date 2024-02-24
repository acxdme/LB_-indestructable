// Jump Game-2 , Greedy approach

#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0, currentReach = 0, maxReach = 0;
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) { // Don't check the last element 
        maxReach = max(maxReach, i + nums[i]);
        if (i == currentReach) {
            jumps++;
            currentReach = maxReach;
        }
    }
    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    int ways = jump(nums);
    cout << "Minimum no. of jumps required : " << ways << endl;
    return 0;
}
