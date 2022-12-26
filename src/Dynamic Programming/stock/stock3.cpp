#include <iostream>
#include <vector>

using namespace std;

// 至多进行两次交易
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len == 0) return 0;
    // dp[i][0]表示第i天不做任何操作
    // dp[i][1]表示第i天是第一次买入的状态
    // dp[i][2]表示第i天是第一次卖出的状态
    // dp[i][3]表示第i天是第二次买入的状态
    // dp[i][4]表示第i天是第二次卖出的状态
    vector<vector<int>> dp(len, vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];

    for (int i = 1; i < len; i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i - 1][1], dp[i][0] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i][1] + prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i][3] + prices[i]);
    }
    return dp[len - 1][4];
}

int main() {
    vector<int> prices = {1, 2, 3, 4, 5};
    int result = maxProfit(prices);
    cout << result << endl;
}