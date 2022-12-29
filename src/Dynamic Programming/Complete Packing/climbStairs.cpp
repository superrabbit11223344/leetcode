#include <iostream>
#include <vector>

using namespace std;

// 爬楼梯进阶版
int climbStairs(int n, int m) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {  // 先遍历背包
        for (int j = 1; j <= m; j++) {  // 再遍历物品
            if (i - j >= 0) dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int main() {
    int result = climbStairs(3, 2); // 需要n阶才能到达楼顶，一次可以爬1, 2, ..., m层台阶
    cout << result << endl;
}