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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> Hash;
        if(head == nullptr || head->next == nullptr)
            return nullptr;   
        ListNode* current = head;
        while(Hash[current] != 1){
            Hash[current]++;
            if(current->next == nullptr)
                return nullptr;
            current = current->next;
        }
        return current;
    }
};