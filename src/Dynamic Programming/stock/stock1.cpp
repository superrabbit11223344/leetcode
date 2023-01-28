#include <iostream>
#include <vector>

using namespace std;

// 只能进行一次交易
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len == 0) return 0;
    // dp[i][0]表示第i天持有股票所得最多现金
    // dp[i][1]表示第i天不持有股票所得现金
    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);
    cout << result << endl;
}