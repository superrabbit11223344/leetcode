#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> result; //用来存储符合条件的序列
vector<int> path;   // 可能的路径

int getSum(vector<int>& vec) {
    // 给定一个序列，返回最后得到的sum值
    if (vec.size() == 1) return vec[0];
    if (vec.size() == 2) return (vec[0] + vec[1]);
    vector<int> vecNext;
    for (int i = 0; i < vec.size() - 1; i++) {
        vecNext.push_back(vec[i] + vec[i + 1]);
    }
    return getSum(vecNext);
}

bool backtracking(int targetSum, vector<int>& nums, vector<int>& used) {
    // 回溯算法，用来获得全排列结果
    // 值得注意的是，这里的backtracking函数的返回值类型是bool，因为只要获得一条符合条件的路径即可
    // 如果返回值是void，则会报Time Limited Error，因为这样会遍历所有可能的结果，导致超时
    // 由于nums数组本身是单调递增的，因此第一条获得的符合条件的路径一定就是字典序最小的结果
    if (path.size() == nums.size() && getSum(path) == targetSum) {
        result.push_back(path);
        return true;
    }
    for (int i = 0; i < nums.size(); i++) {
        // 如果已经取过nums[i]，则跳过该次循环
        if (used[i] == 1) continue;
        // 没有取过nums[i]，标记nums[i]为已使用状态，并将该元素加入path中
        used[i] = 1;
        path.push_back(nums[i]);
        if (backtracking(targetSum, nums, used)) {
            return true;
        }
        // 回溯之前的操作
        path.pop_back();
        used[i] = 0;
    }
    return false;
}


int main() {
    int sum, N;
    // scanf("%d%d", &N, &sum);
    sum = 2832;   // 总和
    N = 10;   // 几个数
    vector<int> nums;

    // 初始化nums数组，比如k=10时，nums的初始化结果为：{1, 2, 3, ..., 9, 10}
    // 之后在回溯时，会每次从nums数组中取对应元素值，从而获得不同的排列结果
    // 比如在N=3时，有{1, 2, 3}, {2, 1, 3}, {1, 3, 2}等情况
    for (int i = 1; i <= N; i++) {
        nums.push_back(i);
    }
    vector<int> used(nums.size(), 0);   // 用来标记nums数组中的哪些元素已经取过，1表示取过，0表示没有取过
    backtracking(sum, nums, used);

    // 打印最终结果
    for (int i = 0; i < N; i++) {
        cout << result[0][i] << " ";
    }
    cout << endl;
}