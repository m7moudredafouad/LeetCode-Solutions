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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left >= right) return head;
        
        ListNode* groupParent = nullptr,
                * firstElement = nullptr,
                * prev = nullptr, *curr = head, *next = head;
        
        int i = 1;
        while(i++ < left){
            groupParent = curr;
            curr = curr->next;
        }
        i = left;
        
        next = firstElement = curr;
         
        while(next != nullptr && i++ <= right) {
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        if(i > right) {
            firstElement->next = next;
            if(groupParent)
                groupParent->next = prev;
        }
        
        
        return left != 1 ? head : prev;
    }
};