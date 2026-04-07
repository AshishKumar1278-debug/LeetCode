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
    bool hasCycle(ListNode *head) {
        map<ListNode* , int> Hash;
        ListNode* current = head;
        int count = 0;
        if(head == nullptr || head->next == nullptr)
            return false;
        while(Hash[current] == 0){
            Hash[current]++;
            if(current->next == nullptr)
                return false;
            current = current->next;
        }
        return true;
    }
};