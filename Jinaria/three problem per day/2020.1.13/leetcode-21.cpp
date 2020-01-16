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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode(0);
        ListNode* ret = newList;
        while(l1 && l2){
            if(l1->val < l2->val){
                newList->next = new ListNode(l1->val);
                newList = newList->next;
                l1 = l1->next;
            }
            else{
                newList->next = new ListNode(l2->val);
                newList = newList->next;
                l2 = l2->next;
            }
        }
        while(l1){
            newList->next = new ListNode(l1->val);
            newList = newList->next;
            l1 = l1->next;
        }
        while(l2){
            newList->next = new ListNode(l2->val);
            newList = newList->next;
            l2 = l2->next;
        }
        ret = ret->next;
        return ret;
    }
};