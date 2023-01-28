#include <iostream>
#include <vector>

using namespace std;

// 买卖股票最佳时机II，可以无限次买入和卖出股票
int maxProfit(vector<int> &prices)
{
    int result = 0;
    int diff = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        diff = prices[i] - prices[i - 1];
        if (diff > 0)
        {
            result += diff;
        }
    }
    return result;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);
    cout << result << endl;
}