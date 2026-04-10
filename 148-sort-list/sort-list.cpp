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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* Merge(ListNode* leftHead, ListNode* rightHead) {
        ListNode* dummy = new ListNode(0);
        ListNode* mover = dummy;
        while (leftHead != NULL && rightHead != NULL) {
            if (leftHead->val <= rightHead->val) {
                mover->next = leftHead;
                leftHead = leftHead->next;
            } else {
                mover->next = rightHead;
                rightHead = rightHead->next;
            }
            mover = mover->next;
        }
        while(leftHead!= NULL){
            mover->next = leftHead;
            leftHead = leftHead->next;
            mover = mover->next;
        }
        while(rightHead!= NULL){
            mover->next = rightHead;
            rightHead = rightHead->next;
            mover = mover->next;
        }
        ListNode* result = dummy->next;
        delete(dummy);
        return result;
    }
    ListNode* MergeSort(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = NULL;
        leftHead = MergeSort(leftHead);
        rightHead = MergeSort(rightHead);

        return Merge(leftHead, rightHead);
    }
    ListNode* sortList(ListNode* head) {
        ListNode* sorted = MergeSort(head);
        return sorted;
    }
};