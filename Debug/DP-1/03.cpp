// debugging for LIS 

#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // int answer = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j]) // fix : compare numbers and not dp values.
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return dp[n - 1];
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << "answer is " << lengthOfLIS(nums) << endl;
    return 0;
}
