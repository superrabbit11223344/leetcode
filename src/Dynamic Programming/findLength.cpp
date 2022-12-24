#include <iostream>
#include <vector>

using namespace std;

// 最长重复子数组
int findLength(vector<int> &nums1, vector<int> &nums2)
{
    // 以nums1[i - 1]结尾的子数组，与以nums2[j - 1]结尾的子数组，最长重复子数组长度为dp[i][j]
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums1.size() + 1));
    int result = 0;
    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = 1; j <= nums2.size(); j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if (result < dp[i][j])
                result = dp[i][j];
        }
    }
    return result;
}

// 滚动数组解法
int findLength_2(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> dp(nums2.size() + 1, 0);
    int result = 0;
    for (int i = 1; i <= nums1.size(); i++)
    {
        // 注意nums2的遍历顺序
        for (int j = nums2.size(); j > 0; j--)
        // for (int j = 0; j <= nums2.size(); j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[j] = dp[j - 1] + 1;
            }
            else
                dp[j] = 0;
            if (result < dp[j])
                result = dp[j];
        }
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    int result = findLength(nums1, nums2);
    int result = findLength_2(nums1, nums2);
    cout << result << endl;
}