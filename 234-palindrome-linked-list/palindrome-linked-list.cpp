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
    bool isPalindrome(ListNode* head) {
        ListNode* start = head;
        ListNode* end = head;
        stack<int> Hash;
        while(end != nullptr){
            Hash.push(end->val);
            end = end->next;
        }
        while(start != nullptr){
            if(start->val == Hash.top()){
                Hash.pop();
                start = start->next;
            }
            else{
                return false;
            }
        }
        return true;

    }
};