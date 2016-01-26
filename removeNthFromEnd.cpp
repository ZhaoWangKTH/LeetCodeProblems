// interviewbit.com/LinkedList/removeNthFromEnd.cpp

/*
  Given a linked list, remove the nth node from the end of list and return its head.

  For example,
  Given linked list: 1->2->3->4->5, and n = 2.
  After removing the second node from the end, the linked list becomes 1->2->3->5.
  
  Note: If n is greater than the size of the list, remove the first node of the list.
  Do it with constant memory space. 
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode* head)
{
    ListNode *prev = NULL;
    while(head != NULL)
    {
        ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    
    return prev;
}
 
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    /*
        reverse the linked list and remove the Nth from head, and then reverse the linkedlist back to before
    */
    ListNode* end = reverseList(A);
    // remove the Bth node from end
    int cnt = 1;
    ListNode dummy(-1);
    dummy.next = end;
    ListNode *prev = &dummy;
    ListNode *cur = end;
    
    while(cur != NULL && cnt != B)
    {
        if(cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
            cnt++;
        }
        else
        {
            prev->next = NULL;
            break;
        }
    }
    // remove cur
    if(cnt == B)
    {
        prev->next = cur->next;
        cur = cur->next;
    }
    // reverse it back
    return reverseList(dummy.next);
}
