// Leetcode Problem/addTwoNumList.cpp

/* Problem Statement
  You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8

    342 + 465 = 807
  Make sure there are no trailing zeros in the output list
  So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/

/* Solution:
  Similar to add two nums in a array, the most important check is the value of "carry" at the end of the list:
  if carry is 1, new ListNode and append,
  else if carry is 0, no operation
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int carry = 0;
    int result = 0;
    ListNode dummy(-1);
    ListNode *p = &dummy;
    
    while(A!=NULL && B!=NULL)
    {
        result = A->val + B->val + carry;
        carry = result/10;
        result = result%10;
        ListNode *temp = new ListNode(result);
        p->next = temp;
        p = p->next;
        A= A->next;
        B = B->next;
    }
    if(A!=NULL)
    {
        while(A!=NULL)
        {
            result = A->val + carry;
            carry = result/10;
            result = result%10;
            ListNode *temp = new ListNode(result);
            p->next = temp;
            p = p->next;
            A = A->next;
        }    
    }
    else if(B!=NULL)
    {
        while(B!=NULL)
        {
            result = B->val + carry;
            carry = result/10;
            result = result%10;
            ListNode *temp = new ListNode(result);
            p->next = temp;
            p = p->next;
            B = B->next;
        }
    }
    
    // the last node
    if(carry == 1)
    {
        ListNode *temp = new ListNode(carry);
        p->next = temp;
        p = p->next;
    }
    
    return dummy.next;
}
