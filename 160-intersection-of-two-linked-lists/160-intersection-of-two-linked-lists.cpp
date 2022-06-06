/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        if(p1 == NULL || p2 == NULL) return NULL;

        int len1 = 1, len2 = 1;
        while(p1 = p1->next) len1++;
        while(p2 = p2->next) len2++;
        
        p1 = headA;
        p2 = headB;
        
        while(len1 > len2 && len1--) p1 = p1->next;
        while(len2 > len1 && len2--) p2 = p2->next;
        
        while(p1 && p2) {
            if(p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        
        return NULL;
    }
};