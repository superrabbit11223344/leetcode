#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructBinaryTree(vector<int> &vec)
{
    vector<TreeNode *> vecTree(vec.size(), NULL);
    TreeNode *root = NULL;
    // 把输入数值数组，先转化为二叉树节点数组
    for (int i = 0; i < vec.size(); i++)
    {
        TreeNode *node = NULL;
        if (vec[i] != -1)
            node = new TreeNode(vec[i]); // 用 -1 表示null
        vecTree[i] = node;
        if (i == 0)
            root = node;
    }
    // 遍历一遍，根据规则左右孩子赋值就可以了
    // 注意这里 结束规则是 i * 2 + 1 < vec.size()，避免空指针
    // 为什么结束规则不能是i * 2 + 2 < arr.length呢?
    // 如果i * 2 + 2 < arr.length 是结束条件
    // 那么i * 2 + 1这个符合条件的节点就被忽略掉了
    // 例如[2,7,9,-1,1,9,6,-1,-1,10] 这样的一个二叉树,最后的10就会被忽略掉
    // 遍历一遍，根据规则左右孩子赋值就可以了

    for (int i = 0; i * 2 + 1 < vec.size(); i++)
    {
        if (vecTree[i] != NULL)
        {
            // 线性存储转连式存储关键逻辑
            vecTree[i]->left = vecTree[i * 2 + 1];
            if (i * 2 + 2 < vec.size())
                vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

int getDepth(TreeNode *cur)
{
    stack<TreeNode *> st;
    if (cur != nullptr)
        st.push(cur);
    int depth = 0;
    int result = 0;
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node != nullptr)
        {
            st.pop();
            st.push(node);
            st.push(nullptr);
            depth++;
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        else
        {
            st.pop();
            node = st.top();
            st.pop();
            depth--;
        }
        result = result > depth ? result : depth;
    }
    return result;
}

// 平衡二叉树，使用迭代法
bool isBalanced(TreeNode *root)
{
    stack<TreeNode *> st;
    if (root == nullptr)
        return true;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        if (abs(getDepth(node->left) - getDepth(node->right)) > 1)
            return false;
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return true;
}

int main()
{
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = constructBinaryTree(nums);
    int depth = getDepth(root);
    cout << depth << endl;
    // bool result = isBalanced(root);
    // cout << result << endl;
}