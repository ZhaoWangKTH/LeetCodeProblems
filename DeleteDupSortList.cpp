// interviewbit.com/DeleteDupSortList.cpp


/**
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL)
        return NULL;
        
    // new dummy 
    ListNode dummy(INT_MIN);
    dummy.next = A;
    
    ListNode* prevNode = &dummy;
    ListNode* curNode = A;
    bool repeated = false;
    
    while(curNode != NULL && curNode->next != NULL)
    {
        if(curNode->val == curNode->next->val)
        {
            // set the flag
            repeated = true;
            // delete curNode->next
            ListNode* temp = curNode->next->next;
            curNode->next = temp;
        }
        else
        {
            if(repeated == true)
            {
                repeated = false;
                // delete curNode
                prevNode->next = curNode->next;
                curNode = curNode->next;
            }
            else
            {
                prevNode = curNode;
                curNode = curNode->next;
            }
        }
    }
    
    if(repeated == true)
        prevNode->next = NULL;
        
    return dummy.next;
}
