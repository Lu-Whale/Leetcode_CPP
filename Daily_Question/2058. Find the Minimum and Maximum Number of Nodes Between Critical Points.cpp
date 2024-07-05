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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int count = 0, firIndex = 0, prevIndex = 0, lastIndex = 0;
        int minDistance = 1e9, maxDistance = 0;
        int prevVal = head->val;
        int index = 0;
        while (head != nullptr) {
            if(head->next != nullptr &&
                ((head->val > prevVal && head->val > head->next->val)
                    || (head->val < prevVal && head->val < head->next->val))) {
                count++;
                if(firIndex == 0) firIndex = index;
                if(prevIndex != 0) minDistance = min(minDistance, index - prevIndex);
                prevIndex = index;
                lastIndex = index;
            }

            index++;
            prevVal = head->val;
            head = head->next;
        }
        if(count < 2) return {-1, -1};
        maxDistance = lastIndex - firIndex;

        return {minDistance, maxDistance};
    }
};