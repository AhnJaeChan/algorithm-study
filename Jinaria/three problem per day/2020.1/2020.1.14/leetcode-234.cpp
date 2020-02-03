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
    bool isPalindrome(ListNode* head){
        if(head == NULL || head->next == NULL)
            return true;
        bool flag = true;
        stack<int> s;
        ListNode* first = head;
        ListNode* second = head->next;
        s.push(first->val);
        while(second->next && second->next->next){
            first = first->next;
            second = second->next->next;
            s.push(first->val);
        }
        first = first->next;
        if(second->next)
            first = first->next;
        while(!s.empty()){
            if(s.top() != first->val){
                flag = false;
                break;
            }
            s.pop();
            first = first->next;
        }
        return flag;
    }
};