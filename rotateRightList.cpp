// LeetCode Problems/rotateRightList.cpp

/* Problem Statement
  Given a list, rotate the list to the right by k places, where k is non-negative.

  For example:

  Given 1->2->3->4->5->NULL and k = 2,
  return 4->5->1->2->3->NULL.
*/

/* The corner point is the scenario that 'B' is larger than the length of the list 
  e.g., For input : 
  A : [ 91 -> 34 -> 18 -> 83 -> 38 -> 82 -> 21 -> 69 ]
  B : 89

  Output is : 69 ->91 -> 34 -> 18 -> 83 -> 38 -> 82 -> 21
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return A;
    
    ListNode *head = A;
    ListNode dummy(-1);
    
    int len = 1;
    while(head->next!=NULL)
    {
        len++;
        head = head->next;
    }
    head->next = A;
    int offset = B%len;
    
    while(len != offset)
    {
        head = head->next;
        len--;
    }
    
    dummy.next = head->next;
    head->next = NULL;
    
    return dummy.next;
}
