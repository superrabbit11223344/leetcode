#include <iostream>
#include <vector>

using namespace std;

int minCut(string s)
{
    // [i, j]范围的子串是否是回文串
    vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                    isPalindrome[i][j] = true;
                else if (isPalindrome[i + 1][j - 1])
                    isPalindrome[i][j] = true;
            }
        }
    }

    // [0, i]范围的子串需要分割的最少次数
    vector<int> dp(s.size(), 0);
    for (int i = 0; i < s.size(); i++)
        dp[i] = i;

    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            // 判断[0, i]范围的子串是否是回文串，如果是，dp[i] = 0，并跳过该次循环
            if (isPalindrome[0][i]) {
                dp[i] = 0;
                continue;
            }
            // 判断[j + 1, i]范围的子串是否是回文串
            if (isPalindrome[j + 1][i])
            {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
    }
    return dp[s.size() - 1];
}

int main() {
    string s = "aabc";
    int result = minCut(s);
    cout << result << endl;
}