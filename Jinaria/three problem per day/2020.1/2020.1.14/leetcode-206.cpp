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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* ret, *tmp, *tmpNext;
        ret = head;
        tmp = head->next;
        if(tmp == NULL)
            return ret;
        tmpNext = tmp->next;
        ret->next = NULL;
        tmp->next = ret;
        while(tmpNext){
            ret = tmp;
            tmp = tmpNext;
            tmpNext = tmpNext->next;
            tmp->next = ret;
        }
        ret = tmp;
        return ret;
    }
};