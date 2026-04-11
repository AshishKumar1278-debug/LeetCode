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
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int size1 = 0, size2 = 0;
        while(temp1 != NULL){
            size1++;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            size2++;
            temp2 = temp2->next;
        }
        ListNode* slow;
        ListNode* fast;
        int diff = 0, count = 0;
        if(size1 > size2){
            diff = size1 - size2;
            fast = headA;
            slow = headB;
        }
        else{
            diff = size2 - size1;
            fast = headB;
            slow = headA;
        }
        while(count != diff){
            fast = fast->next;
            count++;
        }
        while(fast!= NULL && slow != NULL){
            if(fast == slow)
                return fast;
            fast = fast->next;
            slow = slow->next;
        }
        return NULL;
    }
};