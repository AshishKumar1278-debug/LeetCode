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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int size = 0;
        if (head->next == nullptr)
            return nullptr;
        while (current != nullptr) {
            size++;
            current = current->next;
        }
        if(size == n){
            head = head->next;
            return head;
        }
        int k = size - n;
        current = head;
        ListNode* prev;
        for (int i = 0; i < k; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        current->next = nullptr;
        return head;
    }
};