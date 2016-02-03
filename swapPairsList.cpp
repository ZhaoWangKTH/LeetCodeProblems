// LeetCode Problem/swapPairsList.cpp

/* Problem Statement
  Given a linked list, swap every two adjacent nodes and return its head.

  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.

  Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/*
  Solution: 
  New a fake head ListNode dummy(-1) and label it as *p. Then start to append the node in the requested order to the next of *p, while
  maintain *p as the last node of the list. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *head = A; // simply dont like the name of 'A', replace it with 'head'
    ListNode dummy(-1);
    ListNode *p = &dummy;
    
    while(head!=NULL && head->next!=NULL)
    {
        ListNode *temp = head->next->next;
        ListNode *next = head->next;
        
        p->next = next;
        p = p->next;
        p->next = head;
        p = p->next;
        p->next = NULL;
        
        head = temp;
    }
    if(head==NULL)
        return dummy.next;
    else // head->next = NULL
        p->next = head;
        
    return dummy.next;
}
