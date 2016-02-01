// leetcode Problems/revBetweenList.cpp

/* Problem Statement

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int cnt = 0;
    ListNode dummy(-1);
    dummy.next = head;
    
    ListNode *p = &dummy;
    int id = 1;
    while(id != m)
    {
        p = head;
        head = head->next;
        id++;
    }
    // reverse after p
    ListNode *prev = head;
    ListNode *cur = head->next;
    while(cur!=NULL && cnt < (n-m))
    {
        ListNode *next = cur->next;
        cur->next = p->next;
        p->next = cur;
        prev->next = next;
        cur = next;
        cnt++;
    }
    
    return dummy.next;
    
}
