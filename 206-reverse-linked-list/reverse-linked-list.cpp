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
    ListNode* reverseList(ListNode* head) {
        vector<int> v;
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* temp;
        while(head->next != nullptr){
            temp = head;
            v.push_back(head->val);
            head = head->next;
            delete(temp);
        }
        ListNode* mover = head;
        for(int i = v.size() - 1; i >= 0; i--){
            ListNode* NewNode = new ListNode(v[i]);
            mover->next = NewNode;
            mover = NewNode;
        }
        return head;
    }
};