#include <iostream>
#include <vector>

using namespace std;

void test_bagProblem1() {
    vector<int> weight = {1, 3, 4};     // 每个物品的重量
    vector<int> value = {15, 20, 30};   // 每个物品的价值
    int bagweight = 4;                  // 背包容量

    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // 初始化
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    for (int i = 1; i < weight.size(); i++) {
        for (int j = 0; j <= bagweight; j++) {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    // 打印结果
    cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
    test_bagProblem1();
}