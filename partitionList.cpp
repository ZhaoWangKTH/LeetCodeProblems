// LeetCodeProblems/partitionList.cpp

/* Problem statement
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
/*
  Solution
  Reverse the original list, whenever the value is smaller than the target, append it to the end of the candidate list and remove it from the original list. The last step to two connect the tail of the candidate list to the head of the original list. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* head, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode dummy(-1);
    dummy.next = head;          // original list
    
    ListNode dummyHead(INT_MIN);
    ListNode *p = &dummyHead;  // candidate list
    
    ListNode* prev = &dummy;
    while(head != NULL)
    {
        ListNode *next = head->next;
        if(head->val < B)
        {
            // append to the candidate list
            p->next = head;
            p = p->next;
            // remove from the original list
            prev->next = next;
            head = next;
        }
        else
        {
            prev = head;
            head = next;
        }
    }
    p->next = dummy.next;
    
    return dummyHead.next;
}
