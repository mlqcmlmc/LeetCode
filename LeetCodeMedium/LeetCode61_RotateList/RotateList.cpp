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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *pend = head, *plastend = head;
        int n = 0;
        while (pend != NULL)
        {
            plastend = pend;
            ++n;
            pend = pend->next;
        }
        
        int Rk = k%n;
        if (Rk == 0)
        {
            return head;
        }
        ListNode *pp = head;
        for (int i = 0; i<n - Rk - 1; ++i)
        {
            pp = pp->next;
        }
        ListNode* newHead = pp->next;
        plastend->next = head;
        pp->next = NULL;
        return newHead;


    }
};