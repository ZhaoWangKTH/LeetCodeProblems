// Leetcode problems/insertionSortList.cpp
/*
  Sort a linked list by insertion sorting
  Trick: Creat a note dummy and start to append after dummy 
*/


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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);
        
        while(head != NULL)
        {
            ListNode *next = head->next;
            ListNode *p = &dummy;
            while(p->next!=NULL && p->next->val < head->val)
                p = p->next;
            head->next = p->next;
            p->next = head;
            head = next;
        }
        return dummy.next;
    }
};
