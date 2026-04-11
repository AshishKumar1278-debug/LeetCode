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
        if(head == NULL || head->next == NULL){
            return head;
        }
        stack<int> MyStack;
        ListNode* temp = head;
        while(temp->next != NULL){
            MyStack.push(temp->val);
            temp = temp->next;
        }
        head = temp;
        while(!MyStack.empty()){
            ListNode* NextElement = new ListNode(MyStack.top());
            temp->next = NextElement;
            temp = temp->next;
            MyStack.pop();
        }
        return head;
    }
};