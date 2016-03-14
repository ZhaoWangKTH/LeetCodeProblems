//Leetcode problems/mergeKSortList.cpp

/* Problem Statement: Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20 */

/* Solution-I: The time complexity O(n), space complexity O(n) algorithm is given as follows by using Hashmap. */
/* Solution-II: The method without using hashmap will be discussed later. March 14, 2016 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode dummy(-1);
    if(A.size() == 0)
        return dummy.next;
    if(A.size() == 1)
        return A[0];
        
    map<int, vector<ListNode*> > Hash;
    for(int i=0; i<A.size(); i++) {
        ListNode* cur = A[i];
        while(cur!=NULL) {
            Hash[cur->val].push_back(cur);
            cur = cur->next;
        }
    }
    
    // iterate the Hash
    ListNode * cur = &dummy;
    for(map<int, vector<ListNode*>>::iterator it = Hash.begin(); it != Hash.end(); it++) {
        for(int i=0; i<it->second.size(); i++) {
            cur->next = it->second[i];
            cur = cur->next;
        }
    }
    
    return dummy.next;
}
