#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead = reverse(head);

        ListNode* pointer = newHead;
        int flag = 0;
        while (pointer != nullptr) {
            const int num = 2 * pointer->val + flag;
            pointer->val = num % 10;
            flag = num / 10;
            pointer = pointer->next;
        }
        newHead = reverse(newHead);

        return flag == 1 ? new ListNode(1, newHead) : newHead;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};