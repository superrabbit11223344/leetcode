#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int> &nums)
{
    int sum = 0;
    for (int num : nums)
        sum += num;
    int leftSum = 0;
    int rightSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        leftSum += nums[i];
        rightSum = sum - leftSum + nums[i];
        if (leftSum == rightSum)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int result = pivotIndex(nums);
    cout << result << endl;
}