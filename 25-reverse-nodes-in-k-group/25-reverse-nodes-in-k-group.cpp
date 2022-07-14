/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* groupTop = head,
                * lastGroupTop = nullptr,
                * prev, *curr = head, *next = head,
                * returned = head,
                * tmp;
        while(next != nullptr) {
            int x = k;
            prev = nullptr;
            
            tmp = groupTop;
            while(tmp != nullptr && --x) tmp = tmp->next; 
            
            if(x != 0) {
                if(!lastGroupTop) break;
                lastGroupTop->next = next;
                break;
            }

            x = k;
            while(next != nullptr && x--) {
                next = next->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            if(!lastGroupTop) returned = prev; // refers to if it was the first group
            
            if(lastGroupTop) lastGroupTop->next = prev;
            lastGroupTop = groupTop;
            groupTop = next;
        }
        return returned;
    }
};