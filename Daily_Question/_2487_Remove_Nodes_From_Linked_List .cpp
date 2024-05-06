#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class _2487_Remove_Nodes_From_Linked_List {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* tempHead = reverseList(head);

        ListNode* current = tempHead;
        ListNode* pointer = tempHead->next;
        tempHead->next = nullptr;
        int maxVal = tempHead->val;
        while (pointer != nullptr) {
            ListNode* next = pointer->next;
            pointer->next = nullptr;
            if(pointer->val >= maxVal) {
                current->next = pointer;
                current = current->next;
                maxVal = pointer->val;
            }
            pointer = next;
        }

        return reverseList(tempHead);
    }
};

class solution_2487 {
public:

};