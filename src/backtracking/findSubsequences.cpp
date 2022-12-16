#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& nums, int startIndex) {
    if (path.size() >= 2) {
        result.push_back(path);
    }
    unordered_set<int> uset;
    for (int i = startIndex; i < nums.size(); i++) {
        if ((!path.empty() && nums[i] < path.back()) || (uset.find(nums[i]) != uset.end())) {
            continue;
        }
        uset.insert(nums[i]);
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
    }
    return ;
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    result.clear();
    if (nums.size() <= 1) return result;
    backtracking(nums, 0);
    return result;
}

int main() {
    vector<int> vec = {4, 6, 7, 7};
    vector<vector<int>> sequences = findSubsequences(vec);
    for (int i = 0; i < sequences.size(); i++) {
        for (int j = 0; j < sequences[i].size(); j++) {
            cout << sequences[i][j] << " ";
        }
        cout << endl;
    }
}