#include <iostream>
#include <vector>

using namespace std;

// 零钱兑换，计算并返回可以凑成总金额所需的最少的硬币个数
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    // 先遍历物品，后遍历背包，交换顺序也可
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            if (dp[j - coins[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    if (dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = coinChange(coins, amount);
    cout << result << endl;
}