// Leetcode problem/mergeSortList.cpp
/*
  Sort a linked list with time comlexity O(nlog(n))
  
  The following code is based on the mergeSort algorithm analogy to arrays.
  It is very good piece of code by copyright@水中的鱼: http://fisherlei.blogspot.se/2013/12/leetcode-sort-list-solution.html 
  Recursion is very smartly designed. 
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// recursive method at first: this method is very smart designed
ListNode* mergeList(ListNode * head1, ListNode * head2) {
    ListNode dummy(-1);
    ListNode *prev = &dummy;
    
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->val < head2->val)
        {
            prev->next = head1;
            prev = prev->next;
            head1 = head1->next;
        }
        else
        {
            prev->next = head2;
            prev = prev->next;
            head2 = head2->next;
        }
    }
    if(head1 == NULL)
        prev->next = head2;
    else
        prev->next = head1;
        
    return dummy.next;    
}

ListNode * mergeSortList(ListNode ** head, int len) {
    if(len == 1)
    {
        ListNode *temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        return temp; 
    }
    ListNode * leftHead = mergeSortList(head, len/2);
    ListNode * rightHead = mergeSortList(head, len - len/2);
    
    return mergeList(leftHead, rightHead);
}

ListNode* Solution::sortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len = 0;
    ListNode * head = A; // I hate using A as the list head, so instead I force it to be head
    
    ListNode dummy(-1);
    dummy.next = head;
    ListNode * cur = head;
    
    while(cur!=NULL)
    {
        len++;
        cur = cur->next;
    }
    ListNode * newhead = mergeSortList(&head, len);
    return newhead;
}
