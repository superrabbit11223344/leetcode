#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

void printListNode(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 移除链表元素
ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while (cur->next != nullptr) {
        if (cur->next->val == val) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }

    return dummyHead->next;
}

int main() {
    vector<int> vec = {2, 6, 3, 4, 5, 6};
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int num : vec) {
        ListNode* node = new ListNode(num);
        cur->next = node;
        cur = node;
    }
    int val = 6;
    ListNode* result = removeElements(head, val);
    printListNode(result);
}