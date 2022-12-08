#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* constructBinaryTree(vector<int>& vec) {
    vector<TreeNode*> vecTree (vec.size(), NULL);
    TreeNode* root = NULL;
    // 把输入数值数组，先转化为二叉树节点数组
    for (int i = 0; i < vec.size(); i++) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]); // 用 -1 表示null
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    // 遍历一遍，根据规则左右孩子赋值就可以了
    // 注意这里 结束规则是 i * 2 + 1 < vec.size()，避免空指针
    // 为什么结束规则不能是i * 2 + 2 < arr.length呢?
    // 如果i * 2 + 2 < arr.length 是结束条件
    // 那么i * 2 + 1这个符合条件的节点就被忽略掉了
    // 例如[2,7,9,-1,1,9,6,-1,-1,10] 这样的一个二叉树,最后的10就会被忽略掉
    // 遍历一遍，根据规则左右孩子赋值就可以了
           
    for (int i = 0; i * 2 + 1 < vec.size(); i++) {
        if (vecTree[i] != NULL) {
            // 线性存储转连式存储关键逻辑
            vecTree[i]->left = vecTree[i * 2 + 1];
            if(i * 2 + 2 < vec.size())
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

int result;
vector<int> path;
void traversal(TreeNode* cur) {
    if (cur->left == nullptr && cur->right == nullptr) {
        int num = 0;
        for (int i = 0; i < path.size(); i++) {
            num = num * 10 + path[i];
        }
        result += num;
        return ;
    }
    if (cur->left) {
        path.push_back(cur->left->val);
        traversal(cur->left);
        path.pop_back();
    }
    if (cur->right) {
        path.push_back(cur->right->val);
        traversal(cur->right);
        path.pop_back();
    }
    return ;
}
int sumNumbers(TreeNode* root) {
    result = 0;
    path.clear();
    if (root == nullptr) return result;
    path.push_back(root->val);
    traversal(root);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    TreeNode* root = constructBinaryTree(nums);
    int result = sumNumbers(root);
    cout << result << endl;
}