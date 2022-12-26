#include <iostream>
#include <vector>

using namespace std;

// 摆动序列
int wiggleMaxLength(vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums.size();
    int curDiff = 0;
    int preDiff = 0;
    int result = 1; // 默认右端为峰值

    for (int i = 0; i < nums.size() - 1; i++)
    {
        curDiff = nums[i + 1] - nums[i];
        if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0))
        {
            result++;
            preDiff = curDiff;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    int result = wiggleMaxLength(nums);
    cout << result << endl;
}