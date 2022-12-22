#include <iostream>
#include <vector>

using namespace std;

// 零钱兑换
int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1);
    dp[0] = 1;
    // 先遍历物品，后遍历背包
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int change_2(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1);
    dp[0] = 1;
    // 先遍历背包，后遍历物品
    for (int j = 0; j <= amount; j++)
    {
        for (int i = 0; i < coins.size(); i++)
        {
            if (j - coins[i] >= 0)
                dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int main()
{
    int amount = 6;
    vector<int> coins = {1, 5};
    int result1 = change(amount, coins);
    int result2 = change_2(amount, coins);
    cout << result1 << endl;
    cout << result2 << endl;
}