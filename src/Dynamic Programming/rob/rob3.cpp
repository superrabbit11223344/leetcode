#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 根据数组构造二叉树
TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree(vec.size(), nullptr);
    TreeNode* root = nullptr;
    for (int i = 0; i < vec.size(); i++) {
        TreeNode* node = nullptr;
        if (vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i * 2 + 1 < vec.size(); i++) {
        if (vecTree[i] != nullptr) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            if (i * 2 + 2 < vec.size()) 
                vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

vector<int> robTree(TreeNode* cur) {
    if (cur == nullptr) return vector<int>{0, 0};
    vector<int> left = robTree(cur->left);
    vector<int> right = robTree(cur->right);
    // 偷cur，则不能偷左右节点
    int val1 = cur->val + left[0] + right[0];
    // 不偷cur，则可以考虑偷左右节点，取较大值即可
    int val2 = max(left[0], left[1]) + max(right[0], right[1]);
    return {val2, val1};
}

int rob(TreeNode* root) {
    vector<int> result = robTree(root);
    return max(result[0], result[1]);
}

int main() {
    // -1表示null
    vector<int> vec = {3, 2, 3, -1, 3, -1, 1};
    TreeNode* root = construct_binary_tree(vec);
    int result = rob(root);
    cout << result << endl;
}
