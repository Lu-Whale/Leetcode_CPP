//
// Created by 卢京宇 on 5/7/2024.
//

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* pointer = head;
        while (pointer->next != nullptr) {
            ListNode* tempHead = pointer;
            pointer = pointer->next;
            while (pointer->val != 0) {
                tempHead->val += pointer->val;
                pointer = pointer->next;
            }
            tempHead->next = pointer->next == nullptr ? nullptr : pointer;
        }
        return head;
    }
};