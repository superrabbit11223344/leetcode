#include <iostream>
#include <vector>

using namespace std;

// 最长递增子序列的个数
int findNumberOfLIS(vector<int> &nums)
{
    // 以nums[i]结尾的最长递增子序列的长度
    vector<int> dp(nums.size(), 1);
    // 以nums[i]结尾的最长递增子序列的个数
    vector<int> count(nums.size(), 1);
    // 最长递增子序列的长度
    int maxLength = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                // 出现更长的递增子序列
                if (dp[j] + 1 > dp[i])
                {
                    count[i] = count[j];
                    // 出现相同长度的最长递增子序列
                }
                else if (dp[j] + 1 == dp[i])
                {
                    count[i] += count[j];
                }
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            if (dp[i] > maxLength)
                maxLength = dp[i];
        }
    }

    // 统计最长递增子序列的个数
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (dp[i] == maxLength)
        {
            result += count[i];
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    int result = findNumberOfLIS(nums);
    cout << result << endl;
}