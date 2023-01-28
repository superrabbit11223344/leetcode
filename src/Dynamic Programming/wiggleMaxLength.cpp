#include <iostream>
#include <vector>

using namespace std;

// 摆动序列
int wiggleMaxLength(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size(), vector<int>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        dp[i][0] = dp[i][1] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            if (nums[j] > nums[i]) {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        // for (int j = 0; j < i; j++)
        // {
        //     if (nums[j] > nums[i])
        //     {
        //         dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        //     }
        // }
    }
    return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
}

int main()
{
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    int result = wiggleMaxLength(nums);
    cout << result << endl;
}