#include <iostream>
#include <vector>

using namespace std;

// 最长递增子序列
int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    int maxLength = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }
    return maxLength;
}

int main()
{
    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    int result = lengthOfLIS(nums);
    cout << result << endl;
}