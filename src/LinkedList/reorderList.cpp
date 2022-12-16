#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* constructListNode(const vector<int>& vec) {
    if (vec.size() == 0) return nullptr;
    ListNode* head;
    ListNode* cur;
    for (int i = 0; i < vec.size(); i++) {
        if (i == 0) {
            head = new ListNode(vec[0]);
            cur = head;
        } else {
            ListNode* node = new ListNode(vec[i]);
            cur->next = node;
            cur = cur->next;
        }
    }
    return head;
}

void printListNode(ListNode *node)
{
    ListNode *cur = node;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 重排链表
void reorderList(ListNode *head)
{
    if (head == nullptr)
        return;
    deque<ListNode *> que;
    ListNode *cur = head;
    // 把链表转化为双向队列
    while (cur->next != nullptr)
    {
        que.push_back(cur->next);
        cur = cur->next;
    }

    // 一前一后弹出数据
    cur = head;
    ListNode *node;
    int count = 0;
    while (que.size())
    {
        if (count % 2 == 1)
        {
            node = que.front();
            que.pop_front();
        }
        else
        {
            node = que.back();
            que.pop_back();
        }
        count++;
        cur->next = node;
        cur = cur->next;
    }
    cur->next = nullptr;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    ListNode* head = constructListNode(nums);
    printListNode(head);

    // 重排链表
    reorderList(head);
    printListNode(head);
}