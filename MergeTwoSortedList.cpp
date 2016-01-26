// Interviewbit.com/LinkedList/MergeTwoSortedList.cpp 

/*
  Merge two sorted linked lists and return it as a new list. 
  The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

  For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
  The merged list should be :

  4 -> 5 -> 8 -> 11 -> 15 -> 20
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    // interviewbit.com coding style
    ListNode dummy(-1);
    ListNode *resHead = &dummy;
    while(A !=NULL && B!= NULL)
    {
        resHead->next = new ListNode(A->val <= B->val? A->val:B->val);
        resHead = resHead->next;
        if(A->val <= B->val)
            A = A->next;
        else
            B = B->next;
    }
    
    if(A==NULL)
    {
        // append B
        resHead->next = B;
    }
    else
        resHead->next = A;
        
    return dummy.next;
}
