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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev;
        ListNode* current = head;
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        int size = 0;
        while(current != nullptr){
            size++;
            current = current->next;
        }
        int mid = size/2;
        current = head;
        for(int i = 0; i < mid; i++){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        current->next = nullptr;
        return head;
    }
};